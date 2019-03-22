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

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	videoSetModeSub(MODE_0_2D);
	vramSetBankH(VRAM_H_SUB_BG);
	consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 15, 0, false, true);

	sysSetCardOwner (BUS_OWNER_ARM9);

  scanKeys();
	int pressed = keysHeld();

	if (pressed & KEY_A) {
	  runNdsFile("fat:/_nds/extras/bootA.nds", 0, NULL, false);
	} else if (pressed & KEY_B) {
	  runNdsFile("fat:/_nds/extras/bootB.nds", 0, NULL, false);
	} else if (pressed & KEY_X) {
	  runNdsFile("fat:/_nds/ButtonBoot4R4/bootX.nds", 0, NULL, false);
	} else {
	  runNdsFile("fat:/boot.nds", 0, NULL, false);
	}
	if (pressed & KEY_RIGHT) {
		mpusize = 3145728;
	} else if (pressed & KEY_LEFT) {
		mpusize = 1;
	} else {
		mpusize = 0;
				break;
			}
		}
	}
