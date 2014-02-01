#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <fstream>
#include <string>
#include "Tiles.h"
#include "IO.h"
#include <sstream>
#include <vector>

#ifndef _TILEMAP_
#define _TILEMAP_

using namespace std;

class TileMap
{
public:
	TileMap(IO *pIO, Tiles *t);
	void drawMap();
	Tile* getTile(sf::Vector2f pos);
	void upDateTile(sf::Vector2f vec);
	int getWidth();
	int getHeight();

private:
	IO *mIO;
	Tiles *tiles;
	vector<vector<Tile*>> tileVector;
	int width;
	int height;

};

#endif // _TILEMAP_