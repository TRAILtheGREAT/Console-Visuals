#pragma once
#include "Pixel.h"
class ThinPixel : public Pixel
{
public:
	ThinPixel();
	ThinPixel(char character);
	ThinPixel(int color, char character);
	ThinPixel(int frontColor, int backColor, char character);

	void printPixel();
};

/*
* a version of the pixel class that will only print one copy of a character (instead of 2)
* otherwise functions identically to a pixel
*/