/*#include "graphic.h"
u16 bmpImageBuffer[256*192];
u16 videoImageBuffer[39][256*144];

u16 convertToDsBmp(u16 val) {
	if (ms().splash == 1) {
		u16 newVal = ((val>>10)&31) | (val&31<<5) | (val&31)<<10 | BIT(15);

		u8 b,g,r,max,min;
		b = ((newVal)>>10)&31;
		g = ((newVal)>>5)&31;
		r = (newVal)&31;
		// Value decomposition of hsv
		max = (b > g) ? b : g;
		max = (max > r) ? max : r;

		// Desaturate
		min = (b < g) ? b : g;
		min = (min < r) ? min : r;
		max = (max + min) / 2;
		
		newVal = 32768|(max<<10)|(max<<5)|(max);

		b = ((newVal)>>10);
		g = ((newVal)>>5);
		r = (newVal)&31;

		return 32768|(b<<10)|(g<<5)|(r);
	} else {
		buttonStart
	}
}

void LoadBMP(void) {

	if (ms().splash == 1) {	// Show bmp splash if set to 1
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

	fclose(file);*/
