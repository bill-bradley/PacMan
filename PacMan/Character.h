#include "stdafx.h"
#ifndef _CHARACTER_
#define _CHARACTER_
#include "IO.h"

#define CHARACTER_HEIGHT 32
#define CHARACTER_WIDTH 32

#include <SFML\Graphics.hpp>

class Character
{
public:
	Character(IO *pIO);

	void InitChar();
	int GetHeight();
	int GetWidth();
	void MoveChar();
	int mPosX, mPosY;
	void DrawChar();
	int GetPositionX();

private:
	IO *mIO;
	sf::Texture texture;
	
};

#endif // _CHARACTER_