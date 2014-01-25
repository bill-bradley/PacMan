// PacMan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include "TileMap.h"
#include "Pac.h"
//#include "Ghost.h"
#include <iostream>

int main()
{
	IO mIO;
	Character mChar(&mIO);
	TileMap pacmanMap = TileMap(&mIO);
	Pac mPac(&mIO);
	//Ghost mGhost(&mIO);
	int xPos = mIO.GetScreenWidth();
	//std::cout << xPos << std::endl;
	//int ghostPos;

	while (true)
	{
		mIO.ClearScreen();

		/*
		int mKey = mIO.PollKey();
		switch (mKey)
		{
			case (sf::Keyboard::Key::Right) :
			{
				mPac.mPosX+=10;
				break;
			}
			case (sf::Keyboard::Key::Left) :
			{
				mPac.mPosX -= 10;
				break;
			}
			case (sf::Keyboard::Key::Up) :
			{
				mPac.mPosY -= 10;
				break;
			}
			case (sf::Keyboard::Key::Down) :
			{
				mPac.mPosY += 10;
				break;
			}
		}
		*/

		pacmanMap.drawMap();
		mPac.setPosition(sf::Vector2f(1, 1));
		mPac.DrawChar();
		//mChar.DrawChar();
		//mGhost.DrawGhost();
		//ghostPos = mGhost.GetPositionX();
		mIO.UpdateScreen();
	}

	return 0;
}