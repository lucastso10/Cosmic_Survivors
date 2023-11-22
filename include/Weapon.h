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

	int getPierce();
	void setPierce(int p);

	bool checkAttackTimer(sf::Clock* attackTimer);
	
	bool getWasCrit();

	sf::Texture* getBulletTexture();

	void attack(std::vector<Bullet*> bullets, sf::Vector2f playerPos, sf::Vector2f mousePos);

	enum weaponTypes{
		SIMPLE,
		SHOTGUN,
		SPREAD
	};

	weaponTypes type;

private:
	float baseDamage;
	float criticalChance;
	float criticalDamage;
	int pierce;
	sf::Time attackSpeed;
	bool wasCrit;

	sf::Texture* defaultBulletTexture;
	
	
};

#endif
