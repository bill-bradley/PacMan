#include "stdafx.h"
#include <string>
#include "Tile.h"
#include <SFML/Graphics.hpp>

#ifndef _TILES_
#define _TILES_

const int TOTAL_TILES = 12;
const int TILE_HEIGHT = 32;
const int TILE_WIDTH = 32;

// Tiles
const int TILE_EMPTY = 0;
const int TILE_SW = 1;
const int TILE_EW = 2;
const int TILE_ES = 3;
const int TILE_ESW = 4;
const int TILE_NW = 5;
const int TILE_NS = 6;
const int TILE_NSW = 7;
const int TILE_NE = 8;
const int TILE_NEW = 9;
const int TILE_NES = 10;
const int TILE_NESW = 11;

class Tiles
{
public:
	Tiles();
	Tile* allTiles[TOTAL_TILES];

private:
	sf::Texture textureTile;
	sf::Sprite spriteTile;

	void initalizeAllTiles();
};

#endif // _TILES_