//#pragma once
#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
using namespace std;

class Menu {
	int pos;
	bool pressed, theselect;
	Game* game;
	
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Texture* image_option;
	sf::Sprite* bg;
	sf::Sprite* option_bg;

	vector<const char*> options_main_menu;
	vector<sf::Vector2f> coords;
	vector<sf::Text> texts;
	vector<size_t> sizes;

protected:
	void set_values();
	void draw_all();

public:
	Menu(Game *game);
	~Menu();	
	void run_main_menu();
	void run_option_menu();
	void startgame_button();
	void draw_optionmenu();
};

#endif
