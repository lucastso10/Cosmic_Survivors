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
	void shoot(sf::Vector2f direction, sf::Vector2f start_pos);

	void drawBullets(sf::RenderWindow* render);

private:
	float baseDamage;
	float armorPenetration;
	float criticalChance;
	float criticalDamage;
	float attackSpeed;

	sf::Texture* defaultBulletTexture;
	std::vector<Bullet*> bullets;

};

#endif