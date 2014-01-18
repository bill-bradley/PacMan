// PacMan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include "TileMap.h"

int main()
{
	IO mIO;
	Character mChar(&mIO);
	TileMap pacmanMap = TileMap(&mIO);

	while (true)
	{
		mIO.ClearScreen();

		int mKey = mIO.PollKey();
		switch (mKey)
		{
			case (sf::Keyboard::Key::Right) :
			{
				mChar.mPosX+=10;
				break;
			}
			case (sf::Keyboard::Key::Left) :
			{
				mChar.mPosX -= 10;
				break;
			}
			case (sf::Keyboard::Key::Up) :
			{
				mChar.mPosY -= 10;
				break;
			}
			case (sf::Keyboard::Key::Down) :
			{
				mChar.mPosY += 10;
				break;
			}
		}

		pacmanMap.drawMap();
		mChar.DrawChar();

		mIO.UpdateScreen();
	}

	return 0;
}