/*-----------------------------------------------------------------
 Copyright (C) 2005 - 2013
	Michael "Chishm" Chisholm
	Dave "WinterMute" Murphy
	Claudio "sverx"
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
------------------------------------------------------------------*/
#include <nds.h>
#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <fat.h>
#include "common/nds_loader_arm9.h"
#include "inifile.h"
//---------------------------------------------------------------------------------
void stop (void) {
//---------------------------------------------------------------------------------
	while (1) {
		swiWaitForVBlank();
	}
}

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------
const char* settingsini = "sd:/_nds/extras/ButtonBoot.ini";
const char* bootA;
const char* bootB;
const char* bootX;
const char* bootY;
const char* bootL;
const char* bootR;
const char* bootDown;
const char* bootUp;
const char* bootLeft;
const char* bootRight;
const char* bootSelect;

/*std::string bootA;
std::string bootB;
std::string bootX;
std::string bootY;
std::string bootL;
std::string bootR;
std::string bootDown;
std::string bootUp;
std::string bootLeft;
std::string bootRight;
std::string bootSelect;*/

	vramSetBankH(VRAM_H_SUB_BG);
	consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 15, 0, false, true);

	if (!fatInitDefault()) {
		iprintf ("fatInitDefault failed!\n");
		stop();
	}

	bootA = settingsini.GetInt("BUTTONBOOT", "BOOT-A_PATH", bootA);
	bootB = settingsini.GetInt("BUTTONBOOT", "BOOT-B_PATH", bootB);
	bootX = settingsini.GetInt("BUTTONBOOT", "BOOT-X_PATH", bootX);
	bootY = settingsini.GetInt("BUTTONBOOT", "BOOT-Y_PATH", bootY);
	bootL = settingsini.GetInt("BUTTONBOOT", "BOOT-L_PATH", bootL);
	bootR = settingsini.GetInt("BUTTONBOOT", "BOOT-R_PATH", bootR);
	bootDown = settingsini.GetInt("BUTTONBOOT", "BOOT-DOWN_PATH", bootDown);
	bootUp = settingsini.GetInt("BUTTONBOOT", "BOOT-UP_PATH", bootUp);
	bootLeft = settingsini.GetInt("BUTTONBOOT", "BOOT-LEFT_PATH", bootLeft);
	bootRight = settingsini.GetInt("BUTTONBOOT", "BOOT-RIGHT_PATH", bootRight);
	bootSelect = settingsini.GetInt("BUTTONBOOT", "BOOT-SELECT_PATH", bootSelect);

  scanKeys();
	int pressed = keysHeld();

	if (pressed & KEY_A) {
		if((access(bootA, F_OK) == 0)) {
			runNdsFile(bootA, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootA wasn't found!");
			stop();
		}
	} else if (pressed & KEY_B) {
		if((access(bootB, F_OK) == 0)) {
			runNdsFile(bootB, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootB wasn't found!");
			stop();
		}
	} else if (pressed & KEY_X) {
		if((access(bootX, F_OK) == 0)) {
			runNdsFile(bootX, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootX wasn't found!");
			stop();
		}
	} else if (pressed & KEY_Y) {
		if((access(bootY, F_OK) == 0)) {
			runNdsFile(bootY, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootY wasn't found!");
			stop();
		}
	} else if (pressed & KEY_L) {
		if((access(bootL, F_OK) == 0)) {
			runNdsFile(bootL, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootL wasn't found!");
			stop();
		}
	} else if (pressed & KEY_R) {
		if((access(bootR, F_OK) == 0)) {
			runNdsFile(bootR, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootR wasn't found!");
			stop();
		}
	} else if (pressed & KEY_RIGHT) {
		if((access(bootRight, F_OK) == 0)) {
			runNdsFile(bootRight, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootRight wasn't found!");
			stop();
		}
	} else if (pressed & KEY_LEFT) {
		if((access(bootLeft, F_OK) == 0)) {
			runNdsFile(bootLeft, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootLeft wasn't found!");
			stop();
		}
	} else if (pressed & KEY_DOWN) {
		if((access("/_nds/extras/bootDown.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootDown.nds", 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootDown wasn't found!");
			stop();
		}
	} else if (pressed & KEY_UP) {
		if((access(bootUp, F_OK) == 0)) {
			runNdsFile(bootUp, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootUp wasn't found!");
			stop();
		}
	} else if (pressed & KEY_SELECT) {
		if((access(bootSelect, F_OK) == 0)) {
			runNdsFile(bootSelect, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n bootSelect wasn't found!");
			stop();
		}
	} else {
		if((access("/boot.nds", F_OK) == 0)) {
			runNdsFile("/boot.nds", 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n boot.nds wasn't found!");
			stop();
		}
	}
}
