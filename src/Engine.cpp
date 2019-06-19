#include "Engine.hpp"

using namespace sf;
using namespace std;

Engine::Engine(unsigned int WndWidth, unsigned int WndHeight, unsigned int BitsPerPixel, const std::wstring& Title)
	:	_VideoMode(WndWidth, WndHeight, BitsPerPixel), _Title(Title), _Context(),
		_Wnd(_VideoMode, Title, Style::Fullscreen , this->_Context) // style -  разворачивать и закрывать 
{
	this->_BackgroundTexture.loadFromFile("background.jpg");
	this->_BackgroundSprite.setTexture(this->_BackgroundTexture);
	
	this->_StoneTexture.loadFromFile("stone.png");
	this->_StoneSprite1.setTexture(this->_StoneTexture);
	this->_StoneSprite1.setPosition(10 * X_FACTOR, 3 * Y_FACTOR);
	this->_StoneSprite2.setTexture(this->_StoneTexture);
	this->_StoneSprite2.setPosition(5 * X_FACTOR, 6 * Y_FACTOR); 
	this->_StoneSprite3.setTexture(this->_StoneTexture);
	this->_StoneSprite3.setPosition(11 * X_FACTOR, 7 * Y_FACTOR);

	for (int y = 0; y < MAP_HEIGHT; ++y)
	{
		for (int x = 0; x < MAP_WIDTH; ++x)
		{
			if (Map[y][x] == '0')
			{	
				int EntityType = 0 + rand() % (RAND_MAX - 0 + 1);
				if (EntityType % 23 == 0)
				{
					Map[y][x] = 'p';
					this->_Animals.push_back(new Plankton(x, y));
				}
				else if (EntityType % 17 == 0)
				{
					Map[y][x] = 'f';
					this->_Animals.push_back(new Fish(x, y));
				}
				else if (EntityType % 31 == 0)
				{
					Map[y][x] = 'c';
					this->_Animals.push_back(new Catfish(x, y));
				}
			}
		}
	}
}

Engine::~Engine()
{
	if (this->_Wnd.isOpen()) 
		this->_Wnd.close();
}

void Engine::RunEngine()
{
	while (this->_Wnd.isOpen())
	{
		float DeltaTime = this->_HRClock.restart().asSeconds(); //  перезапусает таймер и возвращает до перезапуска.переводит в сегунды

		// Handling window events.
		this->handleEvents(DeltaTime);

		// Updating objects.
		this->update(DeltaTime);

		// Redrawing window.
		this->drawWnd(DeltaTime);

		this_thread::sleep_for(chrono::milliseconds(700));
	}
}

void Engine::handleEvents(float DeltaTime)
{
	if (this->_Wnd.isOpen())
	{
		sf::Event _WndEvents;
		while (this->_Wnd.pollEvent(_WndEvents))
		{
			switch (_WndEvents.type)
			{
				case sf::Event::EventType::Closed:
					this->_Wnd.close();
					break;
				case sf::Event::EventType::KeyPressed:Keyboard::Escape;
				{
					this->_Wnd.close();
					break;
				}

			}
		}
	}
}

void Engine::update(float DeltaTime)
{
	/* Update your objects... */
	list<Entity*> toDel;

	for (auto I = this->_Animals.begin(); I != this->_Animals.end(); ++I)
	{
		if ((*I)->live() == false)
		{
			toDel.push_back(*I);
			Map[(*I)->getY()][(*I)->getX()] = '0';
		}
		else
		{
			CHILD child = (*I)->getChild();
			if (child != CHILD('0', -1, -1))
			{
				Map[child.y][child.x] = child.type;
				switch (child.type)
				{
					case 'p':
						this->_Animals.push_front(new Plankton(child.x, child.y));
						break;
					case 'f':
						this->_Animals.push_front(new Fish(child.x, child.y));
						break;
					case 'c':
						this->_Animals.push_front(new Catfish(child.x, child.y));
						break;
					default:
						break;
				}
			}
		}
	}

	for (auto I : toDel)
	{
		this->_Animals.remove(I);
		delete I;
	}
}

void Engine::drawWnd(float DeltaTime)
{
	// Clearing window and filling it background color.
	this->_Wnd.clear(Color(0, 255, 0, 255));	// RGBA colors

	/* Draw your objects... */
	this->_Wnd.draw(this->_BackgroundSprite);	// Draw sprites.
	
	this->_Wnd.draw(this->_StoneSprite1);
	this->_Wnd.draw(this->_StoneSprite2);
	this->_Wnd.draw(this->_StoneSprite3);
	
	for (auto I : this->_Animals)
	{
		I->draw(this->_Wnd);
	}

	// Redrawing...
	this->_Wnd.display();
}
