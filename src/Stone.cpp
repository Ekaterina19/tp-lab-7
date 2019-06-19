#include "Stone.h"

using namespace sf;
using namespace std;

Stone::Stone(int x, int y)
	: Entity(x, y)
{
	this->texture.loadFromFile("stone.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(x * X_FACTOR, y * Y_FACTOR);
}

Stone::~Stone()
{}

bool Stone::live()
{
	return false;
}