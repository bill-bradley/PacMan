#include "stdafx.h"
#include "Character.h"

Character::Character(IO *pIO, Tiles *t, int tl, int tat)
{
	mIO = pIO;
	tiles = t;
	currentDirection = EAST;
	tileLocation = tl;
	totalAnimationTiles = tat;
	currentAnimationTile = 0;
	InitChar();
}

void Character::InitChar()
{
	DrawChar();
}

void Character::DrawChar()
{
	tiles->getSprite()->setTextureRect(sf::IntRect(32 * (tileLocation+currentAnimationTile), 0, 32, 32));
	tiles->getSprite()->setOrigin(CHARACTER_WIDTH / 2, CHARACTER_WIDTH / 2);

	if (currentDirection == NORTH) 
	{
		tiles->getSprite()->setRotation(270);
	}
	else if (currentDirection == EAST)
	{
		tiles->getSprite()->setRotation(0);
	}
	else if (currentDirection == SOUTH)
	{
		tiles->getSprite()->setRotation(90);
	}
	else if (currentDirection == WEST)
	{
		tiles->getSprite()->setRotation(180);
	}


	tiles->getSprite()->setPosition(
		sf::Vector2f(
			position.x * CHARACTER_WIDTH + offset.x * ((currentDirection == WEST) ? -1 : 1) + CHARACTER_WIDTH / 2, 
			position.y * CHARACTER_HEIGHT + offset.y * ((currentDirection == NORTH) ? -1 : 1) + CHARACTER_HEIGHT / 2
			));

	mIO->DrawSprite(tiles->getSprite());

	tiles->getSprite()->setRotation(0);
	tiles->getSprite()->setOrigin(0, 0);

	if (animationClock.getElapsedTime().asMilliseconds() >= 100)
	{
		animationClock.restart();
		currentAnimationTile++;
		if (currentAnimationTile >= totalAnimationTiles) 
		{
			currentAnimationTile = 0;
		}
	}
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