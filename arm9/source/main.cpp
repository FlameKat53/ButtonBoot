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

	videoSetModeSub(MODE_0_2D);
	vramSetBankH(VRAM_H_SUB_BG);
	consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 15, 0, false, true);

	if (!fatInitDefault()) {
		iprintf ("fatInitDefault failed!\n");
		stop();
	}

  scanKeys();
	int pressed = keysHeld();

	if (pressed & KEY_A) {
		if((access("/_nds/extras/bootA.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootA.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootA.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_B) {
		if((access("/_nds/extras/bootB.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootB.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootB.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_X) {
		if((access("/_nds/extras/bootX.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootX.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootX.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_Y) {
		if((access("/_nds/extras/bootY.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootY.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootY.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_L) {
		if((access("/_nds/extras/bootL.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootL.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootL.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_R) {
		if((access("/_nds/extras/bootR.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootR.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootR.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_RIGHT) {
		if((access("/_nds/extras/bootRight.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootRight.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootRight.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_LEFT) {
		if((access("/_nds/extras/bootLeft.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootLeft.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootLeft.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_DOWN) {
		if((access("/_nds/extras/bootDown.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootDown.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootDown.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_UP) {
		if((access("/_nds/extras/bootUp.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootUp.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootUp.nds wasn't found!");
			stop();
		}
	} else if (pressed & KEY_SELECT) {
		if((access("/_nds/extras/bootSelect.nds", F_OK) == 0)) {
			runNdsFile("/_nds/extras/bootSelect.nds", 0, NULL, false);
		} else {
			printf("Error:\n bootSelect.nds wasn't found!");
			stop();
		}
	} else {
		if((access("/boot.nds", F_OK) == 0)) {
			runNdsFile("/boot.nds", 0, NULL, false);
		} else {
			printf("Error:\n boot.nds wasn't found!");
			stop();
		}
	}
}
