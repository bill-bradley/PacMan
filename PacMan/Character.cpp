#include "stdafx.h"
#include "Character.h"

Character::Character(IO *pIO)
{
	mIO = pIO;
	currentDirection = EAST;
	//InitChar();
}
/*
void Character::InitChar()
{
	texture.loadFromFile("Resources/pacDan.png");
	DrawChar();
}

void Character::DrawChar()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, mPosX, mPosY, texture);
}
*/

direction Character::getDirection() {
	return currentDirection;
}

void Character::setDirection(direction dir) {
	currentDirection = dir;
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

int Character::GetPositionX()
{
	return mPosX;
}



