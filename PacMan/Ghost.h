#include "stdafx.h"
#include "Character.h"
#include "IO.h"
#include <iostream>
#ifndef _GHOST_
#define _GHOST_

#include <SFML\Graphics.hpp>

class Ghost : public Character
{
public:

	Ghost(IO *pIO);
	void InitChar();
private:
	IO *mIO;
};

#endif // _PAC_