//#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"
#include "Weapon.h"

class Player : public Entity
{
private:
	int xp;
	int level;
	// Weapon weapon;

public:
	Player(sf::Sprite sprite, sf::Vector2f start_pos);
	~Player();

	void levelUp();
};

#endif