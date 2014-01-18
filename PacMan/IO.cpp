#include "stdafx.h"
#include "IO.h"

static sf::RenderWindow *mScreen;

IO::IO()
{
	InitGraph();
}

int IO::InitGraph()
{
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