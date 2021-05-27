#pragma once
#include "Sprite.h"
class SmallSprite : public Sprite
{
public:
	SmallSprite() : Sprite() {}
	SmallSprite(std::string forgroundColorFile) : Sprite(forgroundColorFile) {}
	SmallSprite(std::string forgroundColorFile, std::string backgroundColorFile, std::string characterFile) : Sprite(forgroundColorFile, backgroundColorFile, characterFile) {}

	void printAtLocation(int horizontalLocation, int verticalLocation)
	{
		for (int r = 0; r < rows_; r += 2)
		{
			COORD coord = { horizontalLocation, verticalLocation + (r / 2) };
			SetConsoleCursorPosition(hConsole_, coord);
			for (int c = 0; c < cols_; c++)
			{
				SetConsoleTextAttribute(hConsole_, (pixels_[r + 1][c]->getFrontColor() * 16) + pixels_[r][c]->getFrontColor());
				std::cout << (char)223;
			}
		}
	}
};

