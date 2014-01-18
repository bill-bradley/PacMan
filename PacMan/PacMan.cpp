// PacMan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"
#include "IO.h"

int main()
{
	IO mIO;
	while (true)
	{
		mIO.ClearScreen();
		mIO.UpdateScreen();
	}

	return 0;
}