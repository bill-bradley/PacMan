#include "stdafx.h"
#include "Tile.h"

Tile::Tile(int smi, int n, int e, int s, int w)
{
	north = n;
	east = e;
	south = s;
	west = w;
	spriteMapIndex = smi;

}

int Tile::getIndex() {
	return spriteMapIndex;
}
