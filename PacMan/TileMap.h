#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "Tiles.h"
#include <sstream>
#include <vector>

#ifndef _TILEMAP_
#define _TILEMAP_

using namespace std;

class TileMap
{
public:
	TileMap();
	void drawMap();

private:
	Tiles tiles;
	vector<vector<Tile*>> tileVector;

};

#endif // _TILEMAP_