#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Catfish final
	: public Entity
{
public:
	Catfish(int x, int y);

	virtual ~Catfish();

	virtual bool live() override;

	virtual void move(int X, int Y) override;

	virtual void breed() override;

private:

};
