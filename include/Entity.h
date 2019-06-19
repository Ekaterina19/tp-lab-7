#pragma once
#include <SFML/Graphics.hpp>

#include "Map.h"

struct CHILD
{
	char type;
	int x;
	int y;

	CHILD()
		: type('0'), x(-1), y(-1)
	{}

	CHILD(char type, int x, int y)
		: type(type), x(x), y(y)
	{}

	bool operator == (const CHILD& right) const
	{
		if (this->type == right.type	&&
			this->x == right.x			&&
			this->y == right.y)
			return true;
		else
			return false;
		return false;
	}

	bool operator != (const CHILD& right) const
	{
		if (this->type != right.type	||
			this->x != right.x			||
			this->y != right.y)
			return true;
		else
			return false;
		return false;
	}
};

class Entity
{
public:
	Entity(int x, int y);

	virtual ~Entity();

	void draw(sf::RenderWindow& Target);

	virtual bool live() = 0;

	virtual void move(int X, int Y);

	virtual void breed() = 0;

	int getX() const;

	int getY() const;

	CHILD getChild();

private:
	int X;
	int Y;

protected:
	sf::Texture texture;
	sf::Sprite	sprite;

	CHILD Child;
};
