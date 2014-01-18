#include "stdafx.h"
#include "Pac.h"



void Pac::DrawPac()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, mPosX, mPosY, texture);
}

