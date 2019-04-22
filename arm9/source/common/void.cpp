  void buttonStart(void)
  {
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
