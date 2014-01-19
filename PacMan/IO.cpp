#include "stdafx.h"
#include "IO.h"

static sf::RenderWindow *mScreen;

IO::IO()
{
	InitGraph();
}

int IO::InitGraph()
{
	mScreen = new sf::RenderWindow(sf::VideoMode(875, 965), "PacDan");
	return 0;
}

void IO::UpdateScreen()
{
	mScreen->display();
}

void IO::ClearScreen()
{
	mScreen->clear(sf::Color::White);
}

/*
sf::RenderWindow* getScreen(){
	return mScreen;
}
*/

void IO::DrawRectangle(int sX, int sY,int pX, int pY, sf::Texture texture)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(sX, sY));
	rectangle.setTexture(&texture);
	rectangle.setPosition(pX, pY);
	mScreen->draw(rectangle);
}

void IO::DrawSprite(sf::Sprite* sprite)
{
	mScreen->draw((*sprite));
}

int IO::PollKey()
{
	sf::Event event;
	while (mScreen->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mScreen->close();
			break;
		case sf::Event::KeyPressed:
			return event.key.code;
			break;
		default:
			break;
		}

	}
	return sf::Keyboard::Key::Unknown;
}

int IO::GetKey()
{
	sf::Event event;
	while (true)
	{
		mScreen->waitEvent(event);
		if (event.type == event.KeyPressed)
			break;
		if (event.type == sf::Event::Closed)
			mScreen->close();
	};
	return event.KeyPressed;
}

int IO::GetScreenHeight()
{
	return mScreen->getSize().y;
}

int IO::GetScreenWidth()
{
	return mScreen->getSize().x;
}
