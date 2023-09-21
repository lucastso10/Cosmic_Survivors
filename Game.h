//#pragma once
#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

//#include "Entity.h"

class Game
{
private:
	sf::RenderWindow* renderWindow;

	//std::vector<Entity> vectorEntities;

	bool running;

public:

	Game(sf::RenderWindow* window);
	~Game();

	void updateFrame();

	void pollEvents();

	void startGame();

	void pauseGame();

	void quitGame();

	bool isRunning();
};

#endif
