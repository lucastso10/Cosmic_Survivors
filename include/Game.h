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
	Player* player;
	std::vector<Enemy> Enemies;
	bool running; // se a janela está rodando (talvez outros booleanos como pausado e start seriam legais)
	bool inMenu; // Checa se está em algum menu

public:

	Game(sf::RenderWindow* window);
	~Game();

	void movePlayer(sf::Vector2f dist);
	bool getEvents(sf::Event &event);
	bool isInMenu();
	void updateFrame();
	void startGame();
	void pauseGame();
	void quitGame();
	bool isRunning();
};

#endif
