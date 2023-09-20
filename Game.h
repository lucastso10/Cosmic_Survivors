#pragma once

#include "Entity.h"
#include "Controller.h"

class Game
{
private:
	sf::RenderWindow* renderWindow;

	//std::vector<Entity> vectorEntities;

	//Controller controller;

	bool running;

	sf::Event event;
public:

	Game(sf::RenderWindow* window);
	~Game();

	void updateFrame();

	void startGame();

	void pauseGame();

	void quitGame();

	bool isRunning();
};

