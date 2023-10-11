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
	Weapon* weapon;

public:
	Player(std::string file, sf::Texture* bulletTexture, sf::Vector2f start_pos);
	~Player();

	void levelUp();
	void attack(sf::Vector2f direction);
	void drawBullets(sf::RenderWindow* render);
};

#endif