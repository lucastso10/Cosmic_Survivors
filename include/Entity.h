//#pragma once
#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	// removi stationary, um objeto imovel tem que ser sua propria classe!
	float health = 0.0;
	float armor = 0.0;
	float speed = 0.0;
	sf::Texture* texture;
	sf::Sprite sprite;
	

public:

	void setPos(sf::Vector2f pos);
	sf::Vector2f getPos();
	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();
	void setTexture(sf::Texture* texture);
	bool isOnScreen();
	void move(sf::Vector2f direction);
	void onDeath();
	bool isDead();
	sf::FloatRect getBounds(sf::Sprite sprite);


};

#endif

