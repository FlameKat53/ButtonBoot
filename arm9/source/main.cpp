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
const char* ini = "sd:/_nds/extras/ButtonBoot.ini";

std::string bootA;
std::string bootB;
std::string bootX;
std::string bootY;
std::string bootL;
std::string bootR;
std::string bootDown;
std::string bootUp;
std::string bootLeft;
std::string bootRight;
std::string bootSelect;
std::string bootDefault;

	vramSetBankH(VRAM_H_SUB_BG);
	consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 15, 0, false, true);

	if (!fatInitDefault()) {
		iprintf ("fatInitDefault failed!\n");
		stop();
	}

	bootA = ini.GetString("BUTTONBOOT", "BOOT-A_PATH", bootA);
	bootB = ini.GetString("BUTTONBOOT", "BOOT-B_PATH", bootB);
	bootX = ini.GetString("BUTTONBOOT", "BOOT-X_PATH", bootX);
	bootY = ini.GetString("BUTTONBOOT", "BOOT-Y_PATH", bootY);
	bootL = ini.GetString("BUTTONBOOT", "BOOT-L_PATH", bootL);
	bootR = ini.GetString("BUTTONBOOT", "BOOT-R_PATH", bootR);
	bootDown = ini.GetString("BUTTONBOOT", "BOOT-DOWN_PATH", bootDown);
	bootUp = ini.GetString("BUTTONBOOT", "BOOT-UP_PATH", bootUp);
	bootLeft = ini.GetString("BUTTONBOOT", "BOOT-LEFT_PATH", bootLeft);
	bootRight = ini.GetString("BUTTONBOOT", "BOOT-RIGHT_PATH", bootRight);
	bootSelect = ini.GetString("BUTTONBOOT", "BOOT-SELECT_PATH", bootSelect);
	bootDefault = ini.GetString("BUTTONBOOT", "BOOT-DEFAULT_PATH", bootDefault);

  scanKeys();
	int pressed = keysHeld();

	if (pressed & KEY_A) {
		if((access(bootA, F_OK) == 0)) {
			runNdsFile(bootA, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootA);
			stop();
		}
	} else if (pressed & KEY_B) {
		if((access(bootB, F_OK) == 0)) {
			runNdsFile(bootB, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootB);
			stop();
		}
	} else if (pressed & KEY_X) {
		if((access(bootX, F_OK) == 0)) {
			runNdsFile(bootX, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootX);
			stop();
		}
	} else if (pressed & KEY_Y) {
		if((access(bootY, F_OK) == 0)) {
			runNdsFile(bootY, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootY);
			stop();
		}
	} else if (pressed & KEY_L) {
		if((access(bootL, F_OK) == 0)) {
			runNdsFile(bootL, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n %s wasn't found!", bootL);
			stop();
		}
	} else if (pressed & KEY_R) {
		if((access(bootR, F_OK) == 0)) {
			runNdsFile(bootR, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootR);
			stop();
		}
	} else if (pressed & KEY_RIGHT) {
		if((access(bootRight, F_OK) == 0)) {
			runNdsFile(bootRight, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootRight);
			stop();
		}
	} else if (pressed & KEY_LEFT) {
		if((access(bootLeft, F_OK) == 0)) {
			runNdsFile(bootLeft, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootLeft);
			stop();
		}
	} else if (pressed & KEY_DOWN) {
		if((access(bootDown, F_OK) == 0)) {
			runNdsFile(bootDown, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootDown);
			stop();
		}
	} else if (pressed & KEY_UP) {
		if((access(bootUp, F_OK) == 0)) {
			runNdsFile(bootUp, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootUp);
			stop();
		}
	} else if (pressed & KEY_SELECT) {
		if((access(bootSelect, F_OK) == 0)) {
			runNdsFile(bootSelect, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootSelect);
			stop();
		}
	} else {
		if((access(bootDefault, F_OK) == 0)) {
			runNdsFile(bootDefault, 0, NULL, false);
		} else {
			videoSetModeSub(MODE_0_2D);
			printf("Error:\n%s wasn't found!", bootDefault);
			stop();
		}
	}
}
