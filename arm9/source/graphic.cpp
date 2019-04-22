	/*// Display GM9i logo
	bg3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 1, 0);
	bgSetScroll(bg3, 0, 0);
	decompress(image_testBitmap, bgGetGfxPtr(bg3), LZ77Vram);

	// Display for 3 seconds
	for (int i = 0; i < 60*3; i++) {
		swiWaitForVBlank();
	}
*/
void LoadBMP(void) {
	dmaFillHalfWords(0, BG_GFX, 0x18000);

	FILE* file = fopen("/_nds/extras/splash.bmp", "rb");

	if (file) {
		// Start loading
		fseek(file, 0xe, SEEK_SET);
		u8 pixelStart = (u8)fgetc(file) + 0xe;
		fseek(file, pixelStart, SEEK_SET);
		fread(bmpImageBuffer, 2, 0x14000, file);
		u16* src = bmpImageBuffer;
		int x = 0;
		int y = 143;
		for (int i=0; i<256*144; i++) {
			if (x >= 256) {
				x = 0;
				y--;
			}
			u16 val = *(src++);
			BG_GFX[(y+24)*256+x] = convertToDsBmp(val);
			x++;
		}
	}

	fclose(file);
