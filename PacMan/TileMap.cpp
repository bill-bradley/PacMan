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

TileMap::TileMap(IO *pIO)
{
	cout << "Opening map file" << endl;
	ifstream file("Resources/testalltiles.map");
	tiles = Tiles();

	if (file.is_open())
	{
		string s = "";
		vector<string> stringTemp;
		while (getline(file, s)) {
			stringTemp = split(s, ' ');
			vector<Tile*> tempVector;
			for (auto it = begin(stringTemp); it != end(stringTemp); ++it) {
				tempVector.push_back(tiles.allTiles[atoi(it->c_str())]);
			}

			tileVector.push_back(tempVector);
		}
		drawMap();
	}
	else {
		cout << "Failed " << endl;
	}

}

void TileMap::drawMap()
{
	for (auto row = begin(tileVector); row != end(tileVector); ++row) {
		for (auto col = begin(*row); col != end(*row); ++col) {
			cout << (*col)->getIndex() << " ";
		}
		cout << endl;
	}
}