#include "stdafx.h"
#include "Tiles.h"

Tiles::Tiles()
{
	//std::cout << "Loading " << std::endl;
	if (!textureTile.loadFromFile("Resources/pink_tile_set/spritesheet.png")) {
		//std::cout << "Error loading tile" << std::endl;
	}

	spriteTile = sf::Sprite(textureTile);
	initalizeAllTiles();
}

void Tiles::initalizeAllTiles() {
	allTiles[0] = new Tile(0, 0, 0, 0, 0);
	allTiles[1] = new Tile(1, 0, 0, 1, 1);
	allTiles[2] = new Tile(2, 0, 1, 0, 1);
	allTiles[3] = new Tile(3, 0, 1, 1, 0);
	allTiles[4] = new Tile(4, 0, 1, 1, 1);
	allTiles[5] = new Tile(5, 1, 0, 0, 1);
	allTiles[6] = new Tile(6, 1, 0, 1, 0);
	allTiles[7] = new Tile(7, 1, 0, 1, 1);
	allTiles[8] = new Tile(8, 1, 1, 0, 0);
	allTiles[9] = new Tile(9, 1, 1, 0, 1);
	allTiles[10] = new Tile(10, 1, 1, 1, 0);
	allTiles[11] = new Tile(11, 1, 1, 1, 1);
	allTiles[12] = new Tile(12, 0, 0, 0, 0);
	allTiles[13] = new Tile(13, 0, 0, 0, 0);
	allTiles[14] = new Tile(14, 0, 0, 0, 0);
	allTiles[15] = new Tile(15, 0, 0, 0, 0);
	allTiles[16] = new Tile(16, 0, 0, 0, 0);
	allTiles[17] = new Tile(17, 0, 0, 0, 0);
	allTiles[18] = new Tile(18, 0, 0, 0, 0);
	allTiles[19] = new Tile(19, 0, 0, 0, 0);
}

sf::Sprite* Tiles::getSprite() {
	return &spriteTile;
}
