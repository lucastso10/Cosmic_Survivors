//#pragma once
#ifndef _OBJECT_H
#define _OBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Object
{
private:
	sf::Vector2f position;
	sf::Sprite sprite;

public:
	sf::Vector2f getPostion();
	sf::Sprite getSprite();

};

#endif