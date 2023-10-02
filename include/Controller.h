//#pragma once
#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <SFML/Window.hpp>

#include "Game.h"
#include "Menu.h"

class Controller
{
private:
	sf::Event event;
	Game* game;
	Menu* menu;
	std::map<const sf::Keyboard::Key, bool> flags;

public:
	Controller(Game* game, Menu* menu);
	~Controller();

	void eventHandler();
	void eventHandlerGame();
	void eventHandlerMenu();
	void interpretKey();
};

#endif
