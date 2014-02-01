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
	mIO->DrawRectangle(CHARACTER_WIDTH, CHARACTER_HEIGHT, 
		sf::Vector2f(
			position.x * CHARACTER_WIDTH + offset.x * ( (currentDirection == WEST) ? -1 : 1), 
			position.y * CHARACTER_HEIGHT + offset.y * ( (currentDirection == NORTH) ? -1 : 1)),
			texture);
}

void Character::updateOffset()
{
	if (currentDirection == NORTH){
		offset.y += OFFSET;
	} 
	else if (currentDirection == EAST){
		offset.x += OFFSET;
	}
	else if (currentDirection == SOUTH){
		offset.y += OFFSET;
	}
	else if (currentDirection == WEST){
		offset.x += OFFSET;
	}
}


void Character::resetOffset() {
	offset.x = 0;
	offset.y = 0;
}

sf::Vector2<float> Character::getOffset() {
	return offset;
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


