#include "Pixel.h"
Pixel::Pixel()
{
	frontColor_ = 13;
	backColor_ = 0;
	character_ = '%';
}
Pixel::Pixel(char character)
{
	frontColor_ = 7;
	backColor_ = 0;
	character_ = character;
}
Pixel::Pixel(int color, char character)
{
	character_ = character;
	int* colors = splitColors(color);
	frontColor_ = colors[0];
	backColor_ = colors[1];
}
Pixel::Pixel(int frontColor, int backColor, char character)
{
	character_ = character;
	frontColor_ = frontColor;
	backColor_ = backColor;
}



void Pixel::setCharacter(char character)
{
	character_ = character;
}
void Pixel::setColor(int combinedColor)
{
	int* colors = splitColors(combinedColor);
	frontColor_ = colors[0];
	backColor_ = colors[1];
}
void Pixel::setFrontColor(int frontColor)
{
	frontColor_ = frontColor;
}
void Pixel::setBackColor(int backColor)
{
	backColor_ = backColor;
}

int Pixel::getColor()
{
	return combineColors(frontColor_, backColor_);
}
int Pixel::getFrontColor()
{
	return frontColor_;
}
int Pixel::getBackColor()
{
	return backColor_;
}
char Pixel::getCharacter()
{
	return character_;
}

void Pixel::printPixel()
{
	SetConsoleTextAttribute(hConsole_, (int)combineColors(frontColor_, backColor_));
	std::cout << character_ << character_;
}

int Pixel::combineColors(int front, int back)
{
	return front + (back * 16);
}
/*
* returns an pointer to an integer array where the first element represents the front color and the second element represents the back color
*/
int* Pixel::splitColors(int combinedColor)
{
	int* splitColors = new int[2];
	splitColors[0] = combinedColor % 16;
	splitColors[1] = combinedColor / 16;
	return splitColors;
}