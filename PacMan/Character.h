#include "stdafx.h"
#ifndef _CHARACTER_
#define _CHARACTER_
#include "IO.h"
#include "direction.h"

#define CHARACTER_HEIGHT 32
#define CHARACTER_WIDTH 32

#include <SFML\Graphics.hpp>

class Character
{
public:	

	Character(IO *pIO);

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
	

private:
	IO *mIO;
	sf::Vector2<float> position;
	direction currentDirection;
	sf::Texture texture;
	
};

#endif // _CHARACTER_