#include "stdafx.h"
#include "TileMap.h"


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

TileMap::TileMap(IO *pIO, Tiles *t)
{
	mIO = pIO;
	tiles = t;
	//cout << "Opening map file" << endl;
	ifstream file("Resources/square.map");
//	tiles = Tiles();
	height = 0;
	width = 0;
	

	if (file.is_open())
	{
		string s = "";
		vector<string> stringTemp;
		while (getline(file, s)) {			
			stringTemp = split(s, ' ');
			vector<Tile*> tempVector;
			for (auto it = begin(stringTemp); it != end(stringTemp); ++it) {
				
				tempVector.push_back(tiles->allTiles[atoi(it->c_str())]);
			}			
			tileVector.push_back(tempVector);
		}
		height = tileVector.size();
		width = tileVector.front().size();

		cout << height << " " << width << endl;
		drawMap();
	}
	else {
		cout << "Failed " << endl;
	}

}

void TileMap::drawMap()
{
	int rowIndex = 0;
	int colIndex = 0;
	for (auto row = begin(tileVector); row != end(tileVector); ++row, rowIndex++) {
		colIndex = 0;
		for (auto col = begin(*row); col != end(*row); ++col, colIndex++) {
			tiles->getSprite()->setTextureRect(sf::IntRect(32*(*col)->getIndex(),0,32,32));
			tiles->getSprite()->setPosition(sf::Vector2f(32*colIndex, 32*rowIndex));
			mIO->DrawSprite(tiles->getSprite());
		}
	}
}

Tile* TileMap::getTile(sf::Vector2f vec)
{
	return tileVector.at(vec.y).at(vec.x);
}

void TileMap::upDateTile(sf::Vector2f vec)
{
	tileVector[vec.y][vec.x] = tiles->allTiles[TILE_EMPTY];
}

int TileMap::getHeight()
{
	return height;
}

int TileMap::getWidth()
{
	return width;
}