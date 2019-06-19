#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Fish final
	: public Entity
{
public:
	Fish(int x, int y);

	virtual ~Fish();

	virtual bool live() override;

	virtual void move(int X, int Y) override;

	virtual void breed() override;

private:

};
