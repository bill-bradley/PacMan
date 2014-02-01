// PacMan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include "TileMap.h"
#include "Tiles.h"
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

		if (m->getTile(newPos)->getIndex() == TILE_EMPTY || m->getTile(newPos)->getIndex() == TILE_Dot || m->getTile(newPos)->getIndex() == TILE_PowerUp)
		{
			if (m->getTile(newPos)->getIndex() == TILE_Dot)
			{
				m->upDateTile(newPos);
			}
			c->setPosition(newPos);
		}
	} else {
		if (m->getTile(newPos)->getIndex() == TILE_EMPTY || m->getTile(newPos)->getIndex() == TILE_Dot || m->getTile(newPos)->getIndex() == TILE_PowerUp)
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

	if (m->getTile(newPos)->getIndex() == TILE_EMPTY || m->getTile(newPos)->getIndex() == TILE_Dot || m->getTile(newPos)->getIndex() == TILE_PowerUp)
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
	Tiles tiles = Tiles();
	TileMap pacmanMap = TileMap(&mIO, &tiles);
	Pac mPac(&mIO, &tiles, TILE_PacDanClosed, 2);
	mPac.setPosition(sf::Vector2f(1, 1));
	//Ghost mGhost(&mIO);
	int xPos = mIO.GetScreenWidth();

	sf::Clock clock;
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

		if (clock.getElapsedTime().asMilliseconds() >= 25)
		{
			clock.restart();
			moveCharacter(&pacmanMap, &mPac);
		}
		
		mPac.DrawChar();
		//mChar.DrawChar();
		//mGhost.DrawGhost();
		//ghostPos = mGhost.GetPositionX();
		mIO.UpdateScreen();
	}

	return 0;
}