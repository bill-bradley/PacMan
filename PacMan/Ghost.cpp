#include "stdafx.h"
#include "Ghost.h"

void Ghost::DrawGhost()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, mPosX+50, mPosY+50, texture);
}



