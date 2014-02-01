#include "stdafx.h"
#ifndef _CHARACTER_
#define _CHARACTER_
#include "IO.h"
#include "direction.h"
#include "Tiles.h"

#define CHARACTER_HEIGHT 32
#define CHARACTER_WIDTH 32
#define OFFSET 8

#include <SFML\Graphics.hpp>

class Character
{
public:	

	Character(IO *pIO, Tiles *t, int tl, int tat);

	void InitChar();
	int GetHeight();
	int GetWidth();
	void MoveChar();
	void setPosition(sf::Vector2<float> vect);
	sf::Vector2<float> GetPosition();
	void setDirection(direction dir);
	direction getDirection();
	void DrawChar();
	int GetPositionX();
	sf::Texture* GetTexture();
	void updateOffset();
	void resetOffset();
	sf::Vector2<float> getOffset();

private:
	IO *mIO;
	sf::Vector2<float> position;
	sf::Vector2<float> offset;
	direction currentDirection;
	sf::Texture texture;
	Tiles *tiles;
	int tileLocation;
	int totalAnimationTiles;
	int currentAnimationTile;
	sf::Clock animationClock;
};

#endif // _CHARACTER_