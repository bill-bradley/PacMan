#include "stdafx.h"
#include "Character.h"

Character::Character(IO *pIO)
{
	mIO = pIO;
	currentDirection = EAST;
	InitChar();
}

void Character::InitChar()
{
	//texture.loadFromFile("Resources/pacDan.png");
	DrawChar();
}

void Character::DrawChar()
{
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, position, texture);
}

sf::Texture* Character::GetTexture()
{
	return &texture;
}

void Character::setPosition(sf::Vector2<float> vect)
{
	position = vect;
}

sf::Vector2<float> Character::GetPosition()
{
	return position;
}

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




