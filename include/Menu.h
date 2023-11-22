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
	sf::Texture* image_option;
	sf::Sprite* bg;
	sf::Sprite* option_bg;

	vector<const char*> options_main_menu;
	vector<const char*> options_option_menu;
	vector<sf::Vector2f> main_menu_coords;
	vector<sf::Vector2f> option_menu_coords;
	vector<sf::Text> main_menu_texts;
	vector<sf::Text> option_menu_texts;
	vector<size_t> main_menu_sizes;
	vector<size_t> option_menu_sizes;

	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound buttonClick;

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
	void playButtonClick();
	void stopMusic();
};

#endif
