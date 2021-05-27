#pragma once
#include "Pixel.h"
#include <String>
#include <iostream>
#include <fstream>

class Sprite
{
private:
	int rows_;
	int cols_;
	Pixel** pixels_;

	HANDLE hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	Sprite();
	Sprite(std::string forgroundColorFile);
	Sprite(std::string forgroundColorFile, std::string backgroundColorFile, std::string characterFile);

	void printAtLocation(int horizontalLocation, int verticalLocation);

protected:
	int hexToDec(char colorHex);
};