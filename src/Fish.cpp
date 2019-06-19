#include "Fish.h"

using namespace sf;
using namespace std;

Fish::Fish(int x, int y)
	: Entity(x, y)
{
	this->texture.loadFromFile("fish.png");
	this->sprite.setTexture(this->texture);
}

Fish::~Fish()
{}

bool Fish::live()
{
	if (Map[this->getY()][this->getX()] != 'f')
		// Нас съели
		return false;

	// 0, 2, 4, 6, 8 - Никуда
	// 1 - Вверх
	// 3 - Вправо
	// 5 - Вниз
	// 7 - Влево
	int dir = rand() % 9;

	int NextPosX = 0;
	int NextPosY = 0;

	switch (dir)
	{
		case 1:
			// Вверх
			NextPosX = this->getX();
			NextPosY = this->getY() - 1;
			break;
		case 3:
			// Вправо
			NextPosX = this->getX() + 1;
			NextPosY = this->getY();
			break;
		case 5:
			// Вниз
			NextPosX = this->getX();
			NextPosY = this->getY() + 1;
			break;
		case 7:
			// Влево
			NextPosX = this->getX() - 1;
			NextPosY = this->getY();
			break;
		default:
			// Никуда
			break;
	}

	if (!isInBounds(NextPosX, NextPosY))
		// Выход за границы экрана
		return false;

	if (Map[NextPosY][NextPosX] != '0' &&
		Map[NextPosY][NextPosX] != 'p' &&
		Map[NextPosY][NextPosX] != 'f')
		// Нас либо съедят, либо мы разобьёмся о камень
		return true;

	this->move(NextPosX, NextPosY);
	return true;
}

void Fish::move(int X, int Y)
{
	if (Map[Y][X] == 'f')
		this->breed();
	else
	{
		Map[this->getY()][this->getX()] = '0';
		Map[Y][X] = 'f';
		Entity::move(X, Y);
	}
}

void Fish::breed()
{
	int NewPosX = this->getX();
	int NewPosY = this->getY() - 1;
	if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
	{
		// Если верхняя пустая, то генерируем ребёнка там
		this->Child = CHILD('f', NewPosX, NewPosY);
		return;
	}
	else
	{
		NewPosX = this->getX() + 1;
		NewPosY = this->getY();
		if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
		{
			// Если правая пустая, то генерируем ребёнка там
			this->Child = CHILD('f', NewPosX, NewPosY);
			return;
		}
		else
		{
			NewPosX = this->getX();
			NewPosY = this->getY() + 1;
			if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
			{
				// Если нижняя пустая, то генерируем ребёнка там
				this->Child = CHILD('f', NewPosX, NewPosY);
				return;
			}
			else
			{
				NewPosX = this->getX() - 1;
				NewPosY = this->getY();
				if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
				{
					// Если левая пустая, то генерируем ребёнка там
					// Иначе не генерируем вообще
					this->Child = CHILD('f', NewPosX, NewPosY);
					return;
				}
			}
		}
	}
}
