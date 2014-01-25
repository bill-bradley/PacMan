#include "stdafx.h"
#include "Pac.h"

Pac::Pac(IO *mIO) : Character(mIO)
{
	GetTexture()->loadFromFile("Resources/pacDan.png");
	DrawChar();
}


