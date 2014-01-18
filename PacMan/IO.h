#include "stdafx.h"
#include <string>
#ifndef _IO_
#define _IO_

#include <SFML\Graphics.hpp>

class IO
{
public:

	IO();

	int InitGraph();
	void UpdateScreen();
	void ClearScreen();
	void DrawRectangle(int sX, int sY, int pX, int pY, sf::Texture texture);
	void DrawSprite(sf::Sprite* sprite);
	int PollKey();
	int GetKey();
	int GetScreenHeight();
	int GetScreenWidth();
//	sf::RenderWindow* getScreen();

};

#endif // _IO_