//#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

#include "Bullet.h"

class Weapon 
{
public:
	Weapon(sf::Texture* defaultBulletTexture);
	~Weapon();

	float calculateDamage();

	bool checkAttackTimer(sf::Clock* attackTimer);

	sf::Texture* getBulletTexture();

private:
	float baseDamage;
	float armorPenetration;
	float criticalChance;
	float criticalDamage;
	sf::Time attackSpeed;

	sf::Texture* defaultBulletTexture;
	

};

#endif