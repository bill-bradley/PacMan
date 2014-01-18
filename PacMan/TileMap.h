#include "stdafx.h"
#include <SFML/Graphics.hpp>
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
	TileMap(IO *pIO);
	void drawMap();

private:
	Tiles tiles;
	vector<vector<Tile*>> tileVector;

};

#endif // _TILEMAP_