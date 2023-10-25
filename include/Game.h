//#pragma once
#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Enemy.h"
#include "Player.h"
#include "Hud.h"
#include "Weapon.h"

class Game
{
private:
	sf::RenderWindow* renderWindow;
	Player* player;
	Weapon* weapon;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	bool running; // se a janela está rodando (talvez outros booleanos como pausado e start seriam legais)
	bool inMenu; // Checa se está em algum menu
	//int spawnEnemyTimer;

	sf::Clock* attackTimer;
	sf::Mouse mouse;
	Hud* hud;


public:

	Game(sf::RenderWindow* window);
	~Game();

	void movePlayer(sf::Vector2f dist);
	void PlayerAttack(sf::Vector2f direction);
	bool getEvents(sf::Event &event);
	sf::RenderWindow* getRenderWindow();
	bool isInMenu();
	void updateFrame();
	void startGame();
	void pauseGame();
	void quitGame();
	bool isRunning();

	
	
};

#endif
