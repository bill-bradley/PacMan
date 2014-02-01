#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include "Tiles.h"
#include <iostream>
#ifndef _PAC_
#define _PAC_

#include <SFML\Graphics.hpp>

class Pac : public Character
{
public:

	Pac(IO *pIO, Tiles *t, int tat, int tl);
	void InitChar();
private:
	IO *mIO;
};

#endif // _PAC_