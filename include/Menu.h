//#pragma once
#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
using namespace std;

class Menu {
	int pos;
	bool pressed, theselect;
	Game* game;
	
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;

	vector<const char*> options;
	vector<sf::Vector2f> coords;
	vector<sf::Text> texts;
	vector<size_t> sizes;

	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound buttonClick;

protected:
	void set_values();
	void draw_all();

public:
	Menu(Game *game);
	~Menu();	
	void run_menu();
	void startgame_button();
	void playButtonClick();
	void stopMusic();
};

#endif
