#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Menu {
	int pos;
	bool pressed, theselect;
	
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	
	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;

	vector<const char*> options;
	vector < sf::Vector2f> coords;
	vector<sf::Text> texts;
	vector<size_t> sizes;

protected:
	void set_values();
	void loop_events();
	void draw_all();

public:
	Menu();
	~Menu();	
	void run_menu();

};