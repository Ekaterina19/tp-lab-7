#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "Engine.hpp"

using namespace sf; // подключение библиотеки sf 
using namespace std;

int main(int argc, char* argv[], char* env[])
{
	srand(time(NULL));
	
	Engine engine(1366U, 768U, 32U, L"Аквариум");
	engine.RunEngine();

	return 0x0000;
}
