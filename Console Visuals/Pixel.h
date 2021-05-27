#pragma once
#include <windows.h>
#include <iostream>

class Pixel
{
private:
	char character_;
	int frontColor_;
	int backColor_;

	HANDLE hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	Pixel();
	Pixel(char character);
	Pixel(int color, char character);
	Pixel(int frontColor, int backColor, char character);

	void setCharacter(char character);
	void setColor(int combinedColor);
	void setFrontColor(int frontColor);
	void setBackColor(int backColor);

	int getColor();
	int getFrontColor();
	int getBackColor();
	char getCharacter();

	void printPixel();

protected:
	int combineColors(int front, int back);
	int* splitColors(int combinedColor);
};

