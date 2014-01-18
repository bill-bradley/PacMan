#include "stdafx.h"
#include "IO.h"
#include "TileMap.h"

static sf::RenderWindow *mScreen;

IO::IO()
{
	InitGraph();
}

int IO::InitGraph()
{
	TileMap pacmanMap = TileMap();
	mScreen = new sf::RenderWindow(sf::VideoMode(640, 750), "PacDan");
	return 0;
}

void IO::UpdateScreen()
{
	mScreen->display();
}

void IO::ClearScreen()
{
	mScreen->clear();
}