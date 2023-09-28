//#pragma once
#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
private:
	sf::Vector2f local;
	float health;
	float armor;
	float speed;
	bool stationary;
	sf::Sprite sprite;

public:
	Entity(sf::Sprite sprite, sf::Vector2f start_pos, bool stationary);
	~Entity();

	bool isOnScreen();
	void move(sf::Vector2f direction);
	void onDeath();
	bool isDead();

};

#endif

