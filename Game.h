//#pragma once
#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Enemy.h"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* renderWindow;
	Player player;
	std::vector<Entity> Enemies;
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
