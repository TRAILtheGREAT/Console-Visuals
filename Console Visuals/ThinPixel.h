#pragma once
#include "Pixel.h"
/*
* a version of the pixel class that will only print one copy of a character (instead of 2)
* otherwise functions identically to a pixel
*/
class ThinPixel : public Pixel
{
public:
	ThinPixel() : Pixel()
	{

	}
	ThinPixel(char character) : Pixel(character)
	{

	}
	ThinPixel(int color, char character) : Pixel(color, character)
	{

	}
	ThinPixel(int frontColor, int backColor, char character) : Pixel(frontColor, backColor, character)
	{

	}

	void printPixel()
	{
		SetConsoleTextAttribute(hConsole_, (int)combineColors(frontColor_, backColor_));
		std::cout << character_;
	}
};