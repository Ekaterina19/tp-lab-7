#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Plankton final
	: public Entity
{
public:
	Plankton(int x, int y);

	virtual ~Plankton();

	virtual bool live() override;

	virtual void move(int X, int Y) override;

	virtual void breed() override;
};
