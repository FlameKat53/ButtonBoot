#include <nds.h>
#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <fat.h>
#include "common/nds_loader_arm9.h"
#include "inifile.h"
#define CONSOLE_SCREEN_WIDTH 32
#define CONSOLE_SCREEN_HEIGHT 24
bool SplashFound = true;
bool splash = true;
//---------------------------------------------------------------------------------

void stop (void) {

	while (1) {
		swiWaitForVBlank();
	}
}

void BootSplashInit() {

	if (SplashFound) {
		// Do nothing
	} else {
		videoSetMode(MODE_0_2D | DISPLAY_BG0_ACTIVE);
		videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);
		vramSetBankA (VRAM_A_MAIN_BG_0x06000000);
		vramSetBankC (VRAM_C_SUB_BG_0x06200000);
		REG_BG0CNT = BG_MAP_BASE(0) | BG_COLOR_256 | BG_TILE_BASE(2);
		REG_BG0CNT_SUB = BG_MAP_BASE(0) | BG_COLOR_256 | BG_TILE_BASE(2);
		BG_PALETTE[0]=0;
		BG_PALETTE[255]=0xffff;
		u16* bgMapTop = (u16*)SCREEN_BASE_BLOCK(0);
		u16* bgMapSub = (u16*)SCREEN_BASE_BLOCK_SUB(0);
		for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
			bgMapTop[i] = (u16)i;
			bgMapSub[i] = (u16)i;
		}
	}

}
	
void LoadBMP() {
	FILE* file = fopen(("/_nds/extras/splash.bmp"), "rb");

	fseek(file, 0xe, SEEK_SET);
	u8 pixelStart = (u8)fgetc(file) + 0xe;
	fseek(file, pixelStart, SEEK_SET);
	for (int y=191; y>=0; y--) {
		u16 buffer[256];
		fread(buffer, 2, 0x100, file);
		u16* src = buffer;
		for (int i=0; i<256; i++) {
			u16 val = *(src++);
				BG_GFX[0x20000+y*256+i] = ((val>>10)&0x1f) | ((val)&(0x1f<<5)) | (val&0x1f)<<10 | BIT(15);

				fclose(file);
			}
		}
	}
	
void LoadScreen() {
	if (SplashFound) {
		consoleInit(NULL, 0, BgType_Text4bpp, BgSize_T_256x256, 15, 0, true, true);
		consoleClear();

			// Set up background
			videoSetMode(MODE_3_2D | DISPLAY_BG3_ACTIVE);
			vramSetBankD(VRAM_D_MAIN_BG_0x06040000);
			REG_BG3CNT = BG_MAP_BASE(16) | BG_BMP16_256x256;
			REG_BG3X = 0;
			REG_BG3Y = 0;
			REG_BG3PA = 1<<8;
			REG_BG3PB = 0;
			REG_BG3PC = 0;
			REG_BG3PD = 1<<8;

			LoadBMP();
		}
}

int main(int argc, char **argv) {

	std::string bootA = "/_nds/extras/bootA.nds";
	std::string bootB = "/_nds/extras/bootB.nds";
	std::string bootX = "/_nds/extras/bootX.nds";
	std::string bootY = "/_nds/extras/bootY.nds";
	std::string bootL = "/_nds/extras/bootL.nds";
	std::string bootR = "/_nds/extras/bootR.nds";
	std::string bootDown = "/_nds/extras/bootDown.nds";
	std::string bootUp = "/_nds/extras/bootUp.nds";
	std::string bootLeft = "/_nds/extras/bootLeft.nds";
	std::string bootRight = "/_nds/extras/bootRight.nds";
	std::string bootStart = "/_nds/extras/bootStart.nds";
	std::string bootSelect = "/_nds/extras/bootSelect.nds";
	std::string bootTouch = "/_nds/extras/bootTouch.nds";
	std::string bootDefault = "/boot.nds";
	std::string splash = "0"; //0 = off, 1 = on
	std::string splashlength = "1"; //1 = 1 second, max number of seconds not yet known!

	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);
	vramSetBankH(VRAM_H_SUB_BG);
	consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 15, 0, false, true);

	if (!fatInitDefault()) {
		iprintf ("fatInitDefault failed!\n");
		stop();
	}
	CIniFile ini("/_nds/extras/ButtonBoot.ini");
	
	bootA = ini.GetString("BUTTONBOOT", "BOOT_A_PATH", bootA);
	bootB = ini.GetString("BUTTONBOOT", "BOOT_B_PATH", bootB);
	bootX = ini.GetString("BUTTONBOOT", "BOOT_X_PATH", bootX);
	bootY = ini.GetString("BUTTONBOOT", "BOOT_Y_PATH", bootY);
	bootL = ini.GetString("BUTTONBOOT", "BOOT_L_PATH", bootL);
	bootR = ini.GetString("BUTTONBOOT", "BOOT_R_PATH", bootR);
	bootDown = ini.GetString("BUTTONBOOT", "BOOT_DOWN_PATH", bootDown);
	bootUp = ini.GetString("BUTTONBOOT", "BOOT_UP_PATH", bootUp);
	bootLeft = ini.GetString("BUTTONBOOT", "BOOT_LEFT_PATH", bootLeft);
	bootRight = ini.GetString("BUTTONBOOT", "BOOT_RIGHT_PATH", bootRight);
	bootStart = ini.GetString("BUTTONBOOT", "BOOT_START_PATH", bootStart);
	bootSelect = ini.GetString("BUTTONBOOT", "BOOT_SELECT_PATH", bootSelect);
	bootTouch = ini.GetString("BUTTONBOOT", "BOOT_TOUCH_PATH", bootTouch);
	bootDefault = ini.GetString("BUTTONBOOT", "BOOT_DEFAULT_PATH", bootDefault);
	splash = ini.GetString("BUTTONBOOT", "SPLASH", splash);
	splashlength = ini.GetString("BUTTONBOOT", "SPLASH_LENGTH", splashlength);

	ini.SetString("BUTTONBOOT", "BOOT_A_PATH", bootA);
	ini.SetString("BUTTONBOOT", "BOOT_B_PATH", bootB);
	ini.SetString("BUTTONBOOT", "BOOT_X_PATH", bootX);
	ini.SetString("BUTTONBOOT", "BOOT_Y_PATH", bootY);
	ini.SetString("BUTTONBOOT", "BOOT_L_PATH", bootL);
	ini.SetString("BUTTONBOOT", "BOOT_R_PATH", bootR);
	ini.SetString("BUTTONBOOT", "BOOT_DOWN_PATH", bootDown);
	ini.SetString("BUTTONBOOT", "BOOT_UP_PATH", bootUp);
	ini.SetString("BUTTONBOOT", "BOOT_LEFT_PATH", bootLeft);
	ini.SetString("BUTTONBOOT", "BOOT_RIGHT_PATH", bootRight);
	ini.SetString("BUTTONBOOT", "BOOT_START_PATH", bootStart);
	ini.SetString("BUTTONBOOT", "BOOT_SELECT_PATH", bootSelect);
	ini.SetString("BUTTONBOOT", "BOOT_DEFAULT_PATH", bootDefault);
	ini.SetString("BUTTONBOOT", "SPLASH", splash);
	ini.SetString("BUTTONBOOT", "SPLASH_LENGTH", splashlength);

	mkdir("/_nds/",0777);
	mkdir("/_nds/extras/",0777);
	ini.SaveIniFile("/_nds/extras/ButtonBoot.ini");

		if (splash == "1") {

			if (access("/_nds/extras/splash.bmp", F_OK)) SplashFound = false;

			BootSplashInit();

			LoadScreen();
			
			//for (int i = 0; i < 60*3; i++) { swiWaitForVBlank(); }
			for (int i = 0; i < 60*%s; i++, splashlength.c_str()) { swiWaitForVBlank(); }
		}

  scanKeys();
	int pressed = keysHeld();

	if (pressed & KEY_A) {
		if((access(bootA.c_str(), F_OK) == 0)) {
			runNdsFile(bootA.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootA.c_str());
			stop();
		}
	} else if (pressed & KEY_B) {
		if((access(bootB.c_str(), F_OK) == 0)) {
			runNdsFile(bootB.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootB.c_str());
			stop();
		}
	} else if (pressed & KEY_X) {
		if((access(bootX.c_str(), F_OK) == 0)) {
			runNdsFile(bootX.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootX.c_str());
			stop();
		}
	} else if (pressed & KEY_Y) {
		if((access(bootY.c_str(), F_OK) == 0)) {
			runNdsFile(bootY.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootY.c_str());
			stop();
		}
	} else if (pressed & KEY_L) {
		if((access(bootL.c_str(), F_OK) == 0)) {
			runNdsFile(bootL.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootL.c_str());
			stop();
		}
	} else if (pressed & KEY_R) {
		if((access(bootR.c_str(), F_OK) == 0)) {
			runNdsFile(bootR.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootR.c_str());
			stop();
		}
	} else if (pressed & KEY_RIGHT) {
		if((access(bootRight.c_str(), F_OK) == 0)) {
			runNdsFile(bootRight.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootRight.c_str());
			stop();
		}
	} else if (pressed & KEY_LEFT) {
		if((access(bootLeft.c_str(), F_OK) == 0)) {
			runNdsFile(bootLeft.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootLeft.c_str());
			stop();
		}
	} else if (pressed & KEY_DOWN) {
		if((access(bootDown.c_str(), F_OK) == 0)) {
			runNdsFile(bootDown.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootDown.c_str());
			stop();
		}
	} else if (pressed & KEY_UP) {
		if((access(bootUp.c_str(), F_OK) == 0)) {
			runNdsFile(bootUp.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootUp.c_str());
			stop();
		}
	} else if (pressed & KEY_START) {
		if((access(bootStart.c_str(), F_OK) == 0)) {
			runNdsFile(bootStart.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootStart.c_str());
			stop();
		}
	} else if (pressed & KEY_SELECT) {
		if((access(bootSelect.c_str(), F_OK) == 0)) {
			runNdsFile(bootSelect.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootSelect.c_str());
			stop();
		}
	} else if (pressed & KEY_TOUCH) {
		if((access(bootTouch.c_str(), F_OK) == 0)) {
			runNdsFile(bootTouch.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootTouch.c_str());
			stop();
		}
	} else {
		if((access(bootDefault.c_str(), F_OK) == 0)) {
			runNdsFile(bootDefault.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s \nwasn't found!", bootDefault.c_str());
			stop();
		}
	}
}
