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
CIniFile ini((access("sd:/", F_OK) != 0) ? "sd:/_nds/extras/ButtonBoot.ini") : "fat:/_nds/extras/ButtonBoot.ini");

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
std::string bootSelect = "/_nds/extras/bootSelect.nds";
std::string bootDefault = "/boot.nds";

	videoSetModeSub(MODE_0_2D);
	vramSetBankH(VRAM_H_SUB_BG);
	consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 15, 0, false, true);

	if (!fatInitDefault()) {
		iprintf ("fatInitDefault failed!\n");
		stop();
	}
	mkdir("_nds/",0777);
	mkdir("_nds/extras/",0777);
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

	ini.SetString("BUTTONBOOT", "BOOT-A_PATH", bootA);
	ini.SetString("BUTTONBOOT", "BOOT-B_PATH", bootB);
	ini.SetString("BUTTONBOOT", "BOOT-X_PATH", bootX);
	ini.SetString("BUTTONBOOT", "BOOT-Y_PATH", bootY);
	ini.SetString("BUTTONBOOT", "BOOT-L_PATH", bootL);
	ini.SetString("BUTTONBOOT", "BOOT-R_PATH", bootR);
	ini.SetString("BUTTONBOOT", "BOOT-DOWN_PATH", bootDown);
	ini.SetString("BUTTONBOOT", "BOOT-UP_PATH", bootUp);
	ini.SetString("BUTTONBOOT", "BOOT-LEFT_PATH", bootLeft);
	ini.SetString("BUTTONBOOT", "BOOT-RIGHT_PATH", bootRight);
	ini.SetString("BUTTONBOOT", "BOOT-SELECT_PATH", bootSelect);
	ini.SetString("BUTTONBOOT", "BOOT-DEFAULT_PATH", bootDefault);

	ini.SaveIniFile("_nds/extras/ButtonBoot.ini");


  scanKeys();
	int pressed = keysHeld();

	if (pressed & KEY_A) {
		if((access(bootA.c_str(), F_OK) == 0)) {
			runNdsFile(bootA.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootA.c_str());
			stop();
		}
	} else if (pressed & KEY_B) {
		if((access(bootB.c_str(), F_OK) == 0)) {
			runNdsFile(bootB.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootB.c_str());
			stop();
		}
	} else if (pressed & KEY_X) {
		if((access(bootX.c_str(), F_OK) == 0)) {
			runNdsFile(bootX.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootX.c_str());
			stop();
		}
	} else if (pressed & KEY_Y) {
		if((access(bootY.c_str(), F_OK) == 0)) {
			runNdsFile(bootY.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootY.c_str());
			stop();
		}
	} else if (pressed & KEY_L) {
		if((access(bootL.c_str(), F_OK) == 0)) {
			runNdsFile(bootL.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n %s wasn't found!", bootL.c_str());
			stop();
		}
	} else if (pressed & KEY_R) {
		if((access(bootR.c_str(), F_OK) == 0)) {
			runNdsFile(bootR.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootR.c_str());
			stop();
		}
	} else if (pressed & KEY_RIGHT) {
		if((access(bootRight.c_str(), F_OK) == 0)) {
			runNdsFile(bootRight.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootRight.c_str());
			stop();
		}
	} else if (pressed & KEY_LEFT) {
		if((access(bootLeft.c_str(), F_OK) == 0)) {
			runNdsFile(bootLeft.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootLeft.c_str());
			stop();
		}
	} else if (pressed & KEY_DOWN) {
		if((access(bootDown.c_str(), F_OK) == 0)) {
			runNdsFile(bootDown.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootDown.c_str());
			stop();
		}
	} else if (pressed & KEY_UP) {
		if((access(bootUp.c_str(), F_OK) == 0)) {
			runNdsFile(bootUp.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootUp.c_str());
			stop();
		}
	} else if (pressed & KEY_SELECT) {
		if((access(bootSelect.c_str(), F_OK) == 0)) {
			runNdsFile(bootSelect.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootSelect.c_str());
			stop();
		}
	} else {
		if((access(bootDefault.c_str(), F_OK) == 0)) {
			runNdsFile(bootDefault.c_str(), 0, NULL, false);
		} else {
			printf("Error:\n%s wasn't found!", bootDefault.c_str());
			stop();
		}
	}
}
