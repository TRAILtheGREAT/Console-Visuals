//#include "ThinSprite.h"
ThinSprite::ThinSprite()
{
	rows_ = 2;
	cols_ = 2;

	//creating a dynamic array
	pixels_ = new Pixel * [rows_];
	for (int i = 0; i < rows_; i++)
	{
		pixels_[i] = new Pixel[cols_];
	}
	//filling the array with pixels
	for (int r = 0; r < rows_; r++)
	{
		for (int c = 0; c < cols_; c++)
		{
			pixels_[r][c] = ThinPixel(13, 0, '%');
		}
	}
}
ThinSprite::ThinSprite(std::string forgroundColorFile)
{
	rows_ = 0;
	cols_ = 0;
	//pixels_ = new Pixel * [1];
	std::ifstream fileIn;
	fileIn.open(forgroundColorFile);
	std::string line = "";
	if (fileIn.is_open())
	{
		while (std::getline(fileIn, line))//get the number of rows
		{
			rows_++;
			if (line.length() > cols_) cols_ = line.length();
		}
		fileIn.close();
		fileIn.open(forgroundColorFile);//open the file again
		pixels_ = new Pixel * [rows_];//initialize an array of arrays
		int r = 0;
		while (std::getline(fileIn, line))
		{
			if (r > rows_)
			{
				std::cout << "!error in Sprite::Sprite(std::string forgroundColorFile)!";
				break;
			}
			pixels_[r] = new Pixel[cols_];//initialize each array in the array of arrays
			for (int c = 0; c < line.size(); c++)
			{
				if (c > cols_)
				{
					std::cout << "!error in Sprite::Sprite(std::string forgroundColorFile)!";
					break;
				}
				pixels_[r][c] = ThinPixel(hexToDec(line[c]), (char)219);
			}
			r++;
		}
	}
}
ThinSprite::ThinSprite(std::string forgroundColorFile, std::string backgroundColorFile, std::string characterFile)
{
	rows_ = 0;
	cols_ = 0;
	//pixels_ = new Pixel * [1];
	std::ifstream fileIn;
	fileIn.open(forgroundColorFile);
	std::string line = "";
	if (fileIn.is_open())
	{
		while (std::getline(fileIn, line))//get the number of rows
		{
			rows_++;
			if (line.length() > cols_) cols_ = line.length();
		}
		fileIn.close();
		fileIn.open(forgroundColorFile);//open the file again
		pixels_ = new Pixel * [rows_];//initialize an array of arrays
		int r = 0;
		while (std::getline(fileIn, line))
		{
			if (r > rows_)
			{
				std::cout << "!error in Sprite::Sprite(std::string forgroundColorFile)!";
				break;
			}
			pixels_[r] = new Pixel[cols_];//initialize each array in the array of arrays
			for (int c = 0; c < line.size(); c++)
			{
				if (c > cols_)
				{
					std::cout << "!error in Sprite::Sprite(std::string forgroundColorFile)!";
					break;
				}
				pixels_[r][c] = ThinPixel(hexToDec(line[c]), (char)219);
			}
			r++;
		}
	}
	//fill background color
	fileIn.close();
	fileIn.open(backgroundColorFile);
	if (fileIn.is_open())
	{
		int r = 0;
		while (std::getline(fileIn, line))
		{
			for (int c = 0; c < cols_; c++)
			{
				pixels_[r][c].setBackColor(hexToDec(line[c]));
				if (c > cols_)
				{
					std::cout << "backgroundColorFile \"" + backgroundColorFile + "\" has to many characters at row " << r;
					break;
				}
			}
			r++;
			if (r > rows_)
			{
				std::cout << "backgroundColorFile \"" + backgroundColorFile + "\" has to many rows";
				break;
			}
		}
	}
	/*
	* file example:
	* 219,219,219,219
	* 219,219,219,219
	* 219,219,219,219
	* 219,219,219,219
	*/
	fileIn.close();
	fileIn.open(characterFile);
	if (fileIn.is_open())
	{
		for (int r = 0; r < rows_; r++)
		{
			for (int c = 0; c < cols_; c++)
			{
				if (c < cols_ - 1 && std::getline(fileIn, line, ','))//if its not the last character, delimit by commas
				{
					pixels_[r][c].setCharacter((char)std::stoi(line));
				}
				else if (std::getline(fileIn, line, '\n'))//if its the last character, delimit by newline
				{
					pixels_[r][c].setCharacter((char)std::stoi(line));
				}
			}
		}

	}
}

void ThinSprite::printAtLocation(int horizontalLocation, int verticalLocation)
{
	COORD coord = { horizontalLocation, verticalLocation };

	for (int r = 0; r < rows_; r++)
	{
		SetConsoleCursorPosition(hConsole_, coord);
		for (int c = 0; c < cols_; c++)
		{
			
			pixels_[r][c].printPixel();
		}
		coord.Y++;
	}
}