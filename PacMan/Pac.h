#include "stdafx.h"
#include "Character.h"
#ifndef _PAC_
#define _PAC_

#include <SFML\Graphics.hpp>

class Pac : public Character
{
public:

	Pac();
	
	void DrawPac();
};

#endif // _PAC_