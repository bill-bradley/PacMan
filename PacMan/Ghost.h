#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include <iostream>
#ifndef _GHOST_
#define _GHOST_

#include <SFML\Graphics.hpp>

class Ghost : public Character
{
public:

	Ghost(IO *pIO)
		: Character(pIO)
	{
		texture.loadFromFile("Resources/ghost.png");
		DrawGhost();
	}

	void InitChar();
	void DrawGhost();
	void MoveGhost();
private:
	IO *mIO;
	sf::Texture texture;
};

#endif // _PAC_