#pragma once

extern u16 bmpImageBuffer[256*192];
void vramcpy_ui (void* dest, const void* src, int size);
void clearBrightness(void);
void runGraphicIrq(void);
void loadTitleGraphics();
void startRendering(bool top);
bool isRenderingTop();

template<typename T> inline const T abs(T const & x)
{
	return ( x < 0) ? -x : x;
}
