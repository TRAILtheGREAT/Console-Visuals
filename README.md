# Console-Visuals
Create Images in the console using C++

This is a library designed to help computer science students creating their first console programs to put their own primitive pixel and ascii graphics in the console.
It is recommended that you spend some time picking through the source code (it's not that big, only 5 files) before implimenting and using the library as it demonstrates some important concepts in Object-Oriented Programming. I also encourage you to make additions and edits for your own project. Want a convenient method to clean up your code? Add it. Don't like how sprites are represented as text files? Change it. This is a tool and a learning device.

# Functionality
The following section gives a brief explination of how to set up and use this library.

### Setting up the library
to set up the library, download the most recent release and unpack it, then move the files you want into your project. All the header(.h) files are for functionality, while the .cpp and .txt files are for demonstration purposes. In Visual Studio, go to Project > Add Existing Item. Select the files you want to add and press Add. In any file that needs to use the library, use
```java
#include "ConsoleVisuals.h"
```
Now you should have access to all the classes you need.

### Pixel
This represents a pixel or character in a sprite. Its defalut constructor creates a pixel containing magenta percent signs (%) on a black background. Its not inteded to be used on its own.

### Sprite
This represents a basic sprite. Its default constructor creates a 2x2 sprite of default pixels.
```java
Sprite mySprite = Sprite();
```
Its other constructors can be used as such:

Create a sprite by setting its forground colors to the colors in "file.txt":
```java
Sprite mySprite = Sprite("file.txt");
```
All of the pixels will be set to ascii character 219, so each character will be a solid block spanning two characters.

Create a sprite by setting its forground and background colors, as well as setting the characters according to "fg_file.txt", "bg_file.txt", and "ch_file.txt" respectively
```java
Sprite mySprite = Sprite("fg_file.txt", "bg_file.txt", "ch_file.txt");
```

Once a sprite has been initialized, it can be used by calling Sprite.printAtLocation(int horizontalLocation, int verticalLocation)
```java
mySprite.printAtLocation(20, 10);
```
Sprite.printAtLocation(int horizontalLocation, int verticalLocation) will print the sprite to the console such that the upper left pixel of the sprite is at position (horizontalLocation, verticalLocation) on the console. This location is measuresd horizontally from the left side and vertically from the top, with the very upper left of the console being position (0, 0).

### ThinSprite
ThinSprite represents a sprite that will only print each pixel as one character instead of two (so the sprite will be half as wide). This is useful if you want more control over how a sprite is printed. It functions otherwise identically to Sprite. Thinsprite works by populating the pixels with ThinPixel objects instead of Pixel objects. This is the purpose of ThinPixel.

### SmallSprite
SmallSprite represents a sprite that will be printed as a quarter of the size of other sprites. This is accomplished by using character 223 to show two colors in the same slot. Because of this, initializing a smallsprite with background colors or characters will not change how it is printed. It functions otherwise identically to Sprite.

# Formatting Files
For files to be properly read into a sprite, they need to be formatted in a certain way. For the forground and background color files, each of the 16 colors that can used in the console are represented by a hexadecimal character from 0 to f. Below is a list of the codes and their corresponding color. These colors can be changed by users but this represents the default for the windows console.

COLORS:
- 0 = Black
- 1 = Blue
- 2 = Green
- 3 = Light Blue
- 4 = Red
- 5 = Purple
- 6 = Dark Yellow
- 7 = Dull White
- 8 = Grey
- 9 = Navy Blue
- a = Bright Green
- b = Baby Blue
- c = Flesh
- d = Magenta
- e = Dull Yellow
- f = Bright White

The following is an example of a forground or background color file:
```
1ab6
f216
6786
9895
```
This represents a 4x4 sprite. Files can have any name, as long as they are in .txt format.

The following is an example of a character file
```
184,43,43,43
43,184,43,43
43,43,184,43
43,43,43,184

```
This represents a 4x4 sprite. Each number is an [extended ascii](https://theasciicode.com.ar/) code and will be displayed in the order and orientation that is writen in the text file. Ensure that all the files for the same sprite are the same dimentions as using files of different size is likely to cause runtime errors.
