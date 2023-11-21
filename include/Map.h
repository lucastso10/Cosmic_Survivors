//#pragma once
#ifndef _MAP_H
#define _MAP_H

#include <SFML/Graphics.hpp>

class Map
{
private:
	// tamanho do mapa será o tamanho da tela
	sf::Texture* mapTexture;
	sf::Sprite mapSprite;
	
	sf::Texture* backgroundTexture;
	sf::Sprite backgroundSprite;

public:

	Map();
	~Map();

	void drawMap(sf::RenderWindow* render);
	void drawBackground(sf::RenderWindow* render);
};

#endif
