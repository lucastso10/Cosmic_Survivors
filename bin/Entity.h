#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;


class Entity
{
public:
	bool isOnScreen();
	void move();
	void onDeath();


protected:
	Vector2f local;
	float health;
	float armor;
	bool stationary;
	float speed;
	Sprite sprite;

};

