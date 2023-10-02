#pragma once

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
	sf::Sprite* bg;

	vector<const char*> options;
	vector<sf::Vector2f> coords;
	vector<sf::Text> texts;
	vector<size_t> sizes;

protected:
	void set_values();
	void draw_all();

public:
	Menu(Game *game);
	~Menu();	
	void run_menu();
	void startgame_button();
};