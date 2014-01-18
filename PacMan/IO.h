#include "stdafx.h"
#ifndef _IO_
#define _IO_

#include <SFML\Graphics.hpp>

class IO
{
public:

	IO();

	int InitGraph();
	void UpdateScreen();
	void ClearScreen();

};

#endif // _IO_