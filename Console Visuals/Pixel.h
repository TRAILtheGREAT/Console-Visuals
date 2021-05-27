#pragma once
#include <windows.h>
#include <iostream>

class Pixel
{
protected:
	char character_;
	int frontColor_;
	int backColor_;

	HANDLE hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	Pixel()
	{
		frontColor_ = 13;
		backColor_ = 0;
		character_ = '%';
	}
	Pixel(char character)
	{
		frontColor_ = 7;
		backColor_ = 0;
		character_ = character;
	}
	Pixel(int color, char character)
	{
		character_ = character;
		int* colors = splitColors(color);
		frontColor_ = colors[0];
		backColor_ = colors[1];
	}
	Pixel(int frontColor, int backColor, char character)
	{
		character_ = character;
		frontColor_ = frontColor;
		backColor_ = backColor;
	}

	void setCharacter(char character)
	{
		character_ = character;
	}
	void setColor(int combinedColor)
	{
		int* colors = splitColors(combinedColor);
		frontColor_ = colors[0];
		backColor_ = colors[1];
	}
	void setFrontColor(int frontColor)
	{
		frontColor_ = frontColor;
	}
	void setBackColor(int backColor)
	{
		backColor_ = backColor;
	}

	int getColor()
	{
		return combineColors(frontColor_, backColor_);
	}
	int getFrontColor()
	{
		return frontColor_;
	}
	int getBackColor()
	{
		return backColor_;
	}
	char getCharacter()
	{
		return character_;
	}

	virtual void printPixel()
	{
		SetConsoleTextAttribute(hConsole_, (int)combineColors(frontColor_, backColor_));
		std::cout << character_ << character_;
	}

protected:
	int combineColors(int front, int back)
	{
		return front + (back * 16);
	}
	int* splitColors(int combinedColor)
	{
		int* splitColors = new int[2];
		splitColors[0] = combinedColor % 16;
		splitColors[1] = combinedColor / 16;
		return splitColors;
	}
};

