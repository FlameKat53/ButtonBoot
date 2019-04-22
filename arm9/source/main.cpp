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
#include "graphic.h"
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
	std::string splash = "0";
	
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

	mkdir("/_nds/",0777);
	mkdir("/_nds/extras/",0777);
	ini.SaveIniFile("/_nds/extras/ButtonBoot.ini");

// buttonStart
