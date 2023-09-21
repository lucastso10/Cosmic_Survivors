//#pragma once
#ifndef _ENTITY_H
#define _ENTITY_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;


class Entity
{
private:
	Vector2f local;
	float health;
	float armor;
	bool stationary;
	float speed;
	Sprite sprite;

public:
	Entity(sf::Sprite sprite, bool stationary);
	~Entity();

	bool isOnScreen();
	void move(sf::Vector2f direction);
	void onDeath();
	bool isDead();

};

#endif

