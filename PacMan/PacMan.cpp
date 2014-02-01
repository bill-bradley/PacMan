// PacMan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include "TileMap.h"
#include "Pac.h"
//#include "Ghost.h"
#include <iostream>

void moveCharacter(TileMap* m, Character* c) {	
	sf::Vector2f newPos(c->GetPosition().x, c->GetPosition().y);

	if (c->getDirection() == NORTH)
	{
		newPos.y--;
	}
	else if (c->getDirection() == EAST)
	{
		newPos.x++;
	}
	else if (c->getDirection() == SOUTH)
	{
		newPos.y++;
	}
	else if (c->getDirection() == WEST)
	{
		newPos.x--;
	}

	if (newPos.y > m->getHeight()-1)
	{
		newPos.y = 0;
	}
	else if (newPos.y < 0) {
		newPos.y = (float)m->getWidth()-1;
	}
	else if (newPos.x > m->getWidth()-1)
	{
		newPos.x = 0;
	}
	else if (newPos.x < 0) {
		newPos.x = m->getWidth()-1;
	}

	if (c->getOffset().x >= CHARACTER_WIDTH || c->getOffset().y >= CHARACTER_HEIGHT) {
		c->resetOffset();

		if (m->getTile(newPos)->getIndex() == TILE_EMPTY)
		{
			c->setPosition(newPos);
		}
	} else {
		if (m->getTile(newPos)->getIndex() == TILE_EMPTY)
		{
			c->updateOffset();
		}
	}
}

bool validDirection(TileMap* m, Character* c, direction d)
{
	sf::Vector2f newPos(c->GetPosition().x, c->GetPosition().y);
	if (d == NORTH)
	{
		newPos.y--;
	}
	else if (d == EAST)
	{
		newPos.x++;
	}
	else if (d == SOUTH)
	{
		newPos.y++;
	}
	else if (d == WEST)
	{
		newPos.x--;
	}

	if (newPos.y > m->getHeight()-1)
	{
		newPos.y = 0;
	}
	else if (newPos.y < 0) {
		newPos.y = (float)m->getWidth() - 1;
	}
	else if (newPos.x > m->getWidth() - 1)
	{
		newPos.x = 0;
	}
	else if (newPos.x < 0) {
		newPos.x = m->getWidth() - 1;
	}

	if (m->getTile(newPos)->getIndex() == TILE_EMPTY)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	IO mIO;
	Character mChar(&mIO);
	TileMap pacmanMap = TileMap(&mIO);
	Pac mPac(&mIO);
	mPac.setPosition(sf::Vector2f(1, 1));
	//Ghost mGhost(&mIO);
	int xPos = mIO.GetScreenWidth();
	//std::cout << xPos << std::endl;
	//int ghostPos;

	while (true)
	{
		mIO.ClearScreen();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		{
			if (validDirection(&pacmanMap, &mPac, EAST)) {
				mPac.setDirection(EAST);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (validDirection(&pacmanMap, &mPac, WEST)) {
				mPac.setDirection(WEST);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (validDirection(&pacmanMap, &mPac, NORTH)) {
				mPac.setDirection(NORTH);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (validDirection(&pacmanMap, &mPac, SOUTH)) {
				mPac.setDirection(SOUTH);
			}
		}		

		pacmanMap.drawMap();

		moveCharacter(&pacmanMap, &mPac);
		
		mPac.DrawChar();
		//mChar.DrawChar();
		//mGhost.DrawGhost();
		//ghostPos = mGhost.GetPositionX();
		mIO.UpdateScreen();
	}

	return 0;
}