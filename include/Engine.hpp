#pragma once
#ifdef	__Engine_hpp__ 
/*
*	File "Engine.hpp" had already been included.
*/
#else
#define __Engine_hpp__ // Don't use this constant! Re-include protection at compile time.

#include <SFML/Graphics.hpp>
#include <list>
#include <thread>

#include "Map.h"
#include "Entity.h"
#include "Plankton.h"
#include "Fish.h"
#include "Catfish.h"

class Engine
{
public:
	Engine(unsigned int WndWidth, unsigned int WndHeight, unsigned int BitsPerPixel, const std::wstring& Title);

	virtual ~Engine();

	void RunEngine();

private:
	sf::VideoMode		_VideoMode;
	std::wstring		_Title;
	sf::ContextSettings _Context;
	sf::RenderWindow	_Wnd;

	sf::Clock			_HRClock;

	sf::Texture			_BackgroundTexture; 
	sf::Sprite			_BackgroundSprite; // основной объект выводится на экран
	sf::Texture			_StoneTexture;
	sf::Sprite			_StoneSprite1;
	sf::Sprite			_StoneSprite2;
	sf::Sprite			_StoneSprite3;

	std::list<Entity*>	_Animals;

	void handleEvents(float DeltaTime);
	void update(float DeltaTime);
	void drawWnd(float DeltaTime);

protected:
	/*...*/
};

#endif
