// Console Visuals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sprite.h"
#include "ThinPixel.h"
#include "ThinSprite.h"
#include "SmallSprite.h"
#include "SpriteSheet.h"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SpriteSheet s = SpriteSheet(3, 0, 0);
    Sprite sprite = Sprite();
    s.addSprite(sprite);
    sprite = Sprite("alien_forground.txt");
    s.addSprite(sprite);
    sprite = Sprite("alien_background.txt");
    s.addSprite(sprite);

    s.printSprite(0);
    Sleep(1000);
    s.printSprite(1);
    Sleep(1000);
    s.printSprite(2);

    SetConsoleTextAttribute(hConsole, 7);
}

/*
* Pixel = a pixel consisting of the same character twice, with a back and forground
* ThinPixel = a pixel consisting of a single character with background and forground
* 
* Sprite = sprite consisting of an array of Pixels
* ThinSprite = sprite consisting of an array of ThinPixels
* SmallSprite = sprite printed as an array of character 219, uses regular pixels but only the forground color is considered
* PositionSprite = wrapper that stores a pointer to sprite object and a set of coordinates, allows a sprite to be packeged with coordinates
* 
* SpriteSheet = an array of sprites that can be easily interchanged by a public method call
* 
* AnimatedSpriteSheet = a sprite sheet that is automatically animated in a seperate thread *stretch goal
* 
* 
* COLORS:
* 0 = Black
* 1 = Blue
* 2 = Green
* 3 = Light Blue
* 4 = Red
* 5 = Purple
* 6 = Dark Yellow
* 7 = Dull White
* 8 = Grey
* 9 = Navy Blue
* a = Bright Green
* b = Baby Blue
* c = Flesh
* d = Magenta
* e = Dull Yellow
* f = Bright White
* 
* I hate this. c++ is a garbage language. burn it all. Java for life
*/