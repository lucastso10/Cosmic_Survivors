//#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

#include "Bullet.h"

class Weapon 
{
public:
	Weapon();
	~Weapon();

	float calculateDamage();
	void shoot(sf::Vector2f direction);

private:
	float baseDamage;
	float armorPenetration;
	float criticalChance;
	float criticalDamage;
	float attackSpeed;

	std::vector<Bullet*> bullets;

};

#endif