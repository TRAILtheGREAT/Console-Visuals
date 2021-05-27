#pragma once
#include "Sprite.h"
class SpriteSheet
{
private:
	int len_;//length of spriteList
	Sprite** spriteList_;

	int xPos_;
	int yPos_;

public:
	SpriteSheet()
	{
		len_ = 10;
		spriteList_ = new Sprite * [len_];

		xPos_ = 0;
		yPos_ = 0;
	}
	SpriteSheet(int sheetLength)
	{
		len_ = 0;
		spriteList_ = new Sprite * [sheetLength];

		xPos_ = 0;
		yPos_ = 0;
	}
	SpriteSheet(int sheetLength, int xPosition, int yPosition)
	{
		len_ = 0;
		spriteList_ = new Sprite * [sheetLength];

		xPos_ = xPosition;
		yPos_ = yPosition;
	}

	void printSprite(int spriteIndex)
	{
		if (spriteIndex < len_) 
			spriteList_[spriteIndex]->printAtLocation(xPos_, yPos_);
	}
	
	void setPosition(int xPosition, int yPosition)
	{
		xPos_ = xPosition;
		yPos_ = yPosition;
	}

	void addSprite(Sprite sprite)
	{
		len_ += 1;
		spriteList_[len_ - 1] = new Sprite(sprite);
	}
};

