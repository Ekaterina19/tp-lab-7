#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Stone final
	: public Entity
{
public:
	Stone(int x, int y);

	virtual ~Stone();

	virtual bool live() override;

private:

};