#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include <iostream>
#ifndef _PAC_
#define _PAC_

#include <SFML\Graphics.hpp>

class Pac : public Character
{
public:

	Pac(IO *pIO)
	: Character(pIO)
	{

	}
	
	void DrawPac();
};

#endif // _PAC_