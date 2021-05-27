// Console Visuals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sprite.h"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Pixel p = Pixel();

    Sprite s = Sprite("alien_forground.txt", "alien_background.txt", "alien_characters.txt");

    s.printAtLocation(0, 0);

    SetConsoleTextAttribute(hConsole, 7);
}

/*
* Pixel = a pixel consisting of the same character twice, with a back and forground
* ThinPixel = a pixel consisting of a single character with background and forground
* 
* Sprite = sprite consisting of an array of Pixels
* ThinSprite = sprite consisting of an array of ThinPixels
* SmallSprite = sprite printed as an array of character 219, uses regular pixels but only the forground color is considered
* LocatedSprite = wrapper that stores a pointer to sprite object and a set of coordinates, allows a sprite to be packeged with coordinates
* 
* SpriteSheet = an array of sprites that can be easily interchanged by a public method call
* AnimatedSpriteSheet = a sprite sheet that is automatically animated in a seperate thread *stretch
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
* 10 = Bright Green
* 11 = Baby Blue
* 12 = Flesh
* 13 = Magenta
* 14 = Dull Yellow
* 15 = Bright White
*/