#include "stdafx.h"
#include "Ghost.h"

Ghost::Ghost(IO *pIO) : Character(pIO)
{
	GetTexture()->loadFromFile("Resources/ghost.png");
	DrawChar();
}

