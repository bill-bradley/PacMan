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

	std::cout << "X: " << newPos.x << " Y: " << newPos.y << std::endl;
	std::cout << "X: " << newPos.x << " Y: " << newPos.y << std::endl;
	if (m->getTile(newPos)->getIndex() == TILE_EMPTY)
	{
		c->setPosition(newPos);
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

		int mKey = mIO.PollKey();
		switch (mKey)
		{
			case (sf::Keyboard::Key::Right) :
			{
				mPac.setDirection(EAST);
				break;
			}
			case (sf::Keyboard::Key::Left) :
			{
				mPac.setDirection(WEST);
				break;
			}
			case (sf::Keyboard::Key::Up) :
			{
				mPac.setDirection(NORTH);
				break;
			}
			case (sf::Keyboard::Key::Down) :
			{
				mPac.setDirection(SOUTH);
				break;
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