/*
* this file is not required for the execution of the library
* to include the entire library in your project, include "ConsosleVisuals.h"
* below is a domonstration of how to use the Console Visuals library
* the included files "alien_forground.txt", "alien_background.txt", and "alien_characters.txt" provide examples for how to set up files to be read into a sprite
*/

#include <iostream>
#include <conio.h>
#include "ConsoleVisuals.h"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Sprite sprite = Sprite("alien_forground.txt", "alien_background.txt", "alien_characters.txt");
    sprite.printAtLocation(20, 20);

    SmallSprite smallSprite = SmallSprite("alien_forground.txt");
    smallSprite.printAtLocation(60, 20);

    SpriteSheet s = SpriteSheet(3, 0, 0);
    sprite = Sprite();
    s.addSprite(sprite);
    sprite = Sprite("alien_forground.txt");
    s.addSprite(sprite);
    sprite = Sprite("alien_background.txt");
    s.addSprite(sprite);

    _getch();
    s.printSprite(0);
    _getch();
    s.printSprite(1);
    _getch();
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
* 
* SpriteSheet = an array of sprites that can be easily interchanged by a public method call
* 
* AnimatedSpriteSheet = a sprite sheet that is automatically animated in a seperate thread *stretch goal* !not yet implimented!
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