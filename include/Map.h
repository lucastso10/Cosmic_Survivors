//#pragma once
#ifndef _MAP_H
#define _MAP_H

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Map
{
private:
	sf::Vector2f size;
	sf::Texture texture;

public:

	Map(std::string file);
	~Map();

	sf::Vector2f getSize();
	sf::Texture getTexture();

};

#endif
