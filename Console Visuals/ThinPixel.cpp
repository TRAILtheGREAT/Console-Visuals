//#include "ThinPixel.h"
ThinPixel::ThinPixel() : Pixel()
{

}
ThinPixel::ThinPixel(char character) : Pixel(character)
{

}
ThinPixel::ThinPixel(int color, char character) : Pixel(color, character)
{

}
ThinPixel::ThinPixel(int frontColor, int backColor, char character) : Pixel(frontColor, backColor, character)
{

}

void ThinPixel::printPixel()
{
	SetConsoleTextAttribute(hConsole_, (int)combineColors(frontColor_, backColor_));
	std::cout << character_;
}