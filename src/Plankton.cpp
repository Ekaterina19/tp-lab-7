#include "Plankton.h"

using namespace sf;
using namespace std;

Plankton::Plankton(int x, int y)
	: Entity(x, y)
{
	this->texture.loadFromFile("plankton.png");
	this->sprite.setTexture(this->texture);
}

Plankton::~Plankton()
{}

bool Plankton::live()
{
	if (Map[this->getY()][this->getX()] != 'p')
		// ��� �����
		return false;

	// 0, 2, 4, 6, 8 - ������
	// 1 - �����
	// 3 - ������
	// 5 - ����
	// 7 - �����
	int dir = rand() % 9;

	int NextPosX = 0;
	int NextPosY = 0;

	switch (dir)
	{
		case 1:
			// �����
			NextPosX = this->getX();
			NextPosY = this->getY() - 1;
			break;
		case 3:
			// ������
			NextPosX = this->getX() + 1;
			NextPosY = this->getY();
			break;
		case 5:
			// ����
			NextPosX = this->getX();
			NextPosY = this->getY() + 1;
			break;
		case 7:
			// �����
			NextPosX = this->getX() - 1;
			NextPosY = this->getY();
			break;
		default:
			// ������
			break;
	}

	if (!isInBounds(NextPosX, NextPosY))
		// ����� �� ������� ������
		return false;

	if (Map[NextPosY][NextPosX] != '0' && 
		Map[NextPosY][NextPosX] != 'p')
		// ��� ���� ������, ���� �� ���������� � ������
		return true;

	this->move(NextPosX, NextPosY);
	return true;
}

void Plankton::move(int X, int Y)
{
	if (Map[Y][X] == 'p')
		this->breed();
	else
	{
		Map[this->getY()][this->getX()] = '0';
		Map[Y][X] = 'p';
		Entity::move(X, Y);
	}
}

void Plankton::breed()
{
	int NewPosX = this->getX();
	int NewPosY = this->getY() - 1;
	if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
	{
		// ���� ������� ������, �� ���������� ������ ���
		this->Child = CHILD('p', NewPosX, NewPosY);
		return;
	}
	else
	{
		NewPosX = this->getX() + 1;
		NewPosY = this->getY();
		if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
		{
			// ���� ������ ������, �� ���������� ������ ���
			this->Child = CHILD('p', NewPosX, NewPosY);
			return;
		}
		else
		{
			NewPosX = this->getX();
			NewPosY = this->getY() + 1;
			if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
			{
				// ���� ������ ������, �� ���������� ������ ���
				this->Child = CHILD('p', NewPosX, NewPosY);
				return;
			}
			else
			{
				NewPosX = this->getX() - 1;
				NewPosY = this->getY();
				if (isInBounds(NewPosX, NewPosY) && Map[NewPosY][NewPosX] == '0')
				{
					// ���� ����� ������, �� ���������� ������ ���
					// ����� �� ���������� ������
					this->Child = CHILD('p', NewPosX, NewPosY);
					return;
				}
			}
		}
	}
}
