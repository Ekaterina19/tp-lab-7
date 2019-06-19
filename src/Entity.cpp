#include "Entity.h"

using namespace sf;
using namespace std;

Entity::Entity(int x, int y)
	: X(x), Y(y)
{
	this->sprite.setPosition(x * X_FACTOR, y * Y_FACTOR);
}

Entity::~Entity()
{}

void Entity::draw(RenderWindow& Target)
{
	Target.draw(this->sprite);
}

void Entity::move(int X, int Y)
{
	this->X = X;
	this->Y = Y;
	this->sprite.setPosition(X * X_FACTOR, Y * Y_FACTOR);
}

int Entity::getX() const
{
	return this->X;
}

int Entity::getY() const
{
	return this->Y;
}

CHILD Entity::getChild()
{
	CHILD child = this->Child;
	this->Child = CHILD('0', -1, -1);
	return child;
}
