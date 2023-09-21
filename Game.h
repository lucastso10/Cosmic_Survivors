//#pragma once
#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

	bool getEvents(sf::Event &event);
	void updateFrame();
	void startGame();
	void pauseGame();
	void quitGame();
	bool isRunning();
};

#endif
