//#pragma once
#ifndef _MAP_H
#define _MAP_H

#include <SFML/Graphics.hpp>

class Map
{
private:
	// tamanho do mapa será o tamanho da tela
	sf::Texture* texture;
	sf::Sprite sprite;

public:

	Map(std::string arquivo);
	~Map();

	void drawMap(sf::RenderWindow* render);
};

#endif
