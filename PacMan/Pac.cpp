#include "stdafx.h"
#include "Pac.h"

Pac::Pac(IO *mIO) : Character(mIO)
{
	texture.loadFromFile("Resources/pacDan.png");
	DrawPac();
}

void Pac::DrawPac()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, mPosX, mPosY, texture);
}

