#include "stdafx.h"
#include <SFML/Graphics.hpp>

#ifndef _TILE_
#define _TILE_

class Tile
{
public:
	Tile(int smi, int n, int e, int s, int w);

 private:
	 int spriteMapIndex;
	 int north;
	 int east;
	 int south;
	 int west;

};

#endif // _TILE_