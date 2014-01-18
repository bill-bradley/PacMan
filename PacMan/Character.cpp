#include "stdafx.h"
#include "Character.h"

Character::Character(IO *pIO)
{
	mIO = pIO;
	InitChar();
}

void Character::InitChar()
{
	texture.loadFromFile("Resources/pacDan.png");
	DrawChar();
}

void Character::DrawChar()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, mPosX, mPosY, texture);
}

int Character::GetHeight()
{
	return CHARACTER_HEIGHT;
}

int Character::GetWidth()
{
	return CHARACTER_WIDTH;
}

void Character::MoveChar()
{
	
}


