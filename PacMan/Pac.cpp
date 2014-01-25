#include "stdafx.h"
#include "Pac.h"

Pac::Pac(IO *mIO) : Character(mIO)
{
	GetTexture()->loadFromFile("Resources/pacDan.png");
	DrawChar();
}

/*
void Pac::DrawPac()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, mPosX, mPosY, texture);
}

*/

