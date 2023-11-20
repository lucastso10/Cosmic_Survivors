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

	bool isWalking;


public:
	Player(std::string file, sf::Vector2f start_pos);
	~Player();

	void setWalking(bool moving);

	void animate();

	void levelUp();

	int getXp();

	int setXp(int xp);

	int setXp();

	void incrementXp(int xpDrop);

	int getLevel();
	
	bool checkAttackTimer(sf::Clock* attackTimer);
};

#endif