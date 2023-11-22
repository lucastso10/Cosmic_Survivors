#include "Weapon.h"
#include <iostream>

Weapon::Weapon(sf::Texture* defaultBulletTexture)
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 10.0;
	this->criticalChance = 50; // número em porcentagem por exemplo 25,5 pra 25,5% de chance
	this->criticalDamage = 2;
	this->attackSpeed = sf::seconds(1.0f);
	this->pierce = 1;

	this->defaultBulletTexture = defaultBulletTexture;
	
	this->wasCrit = false;
}

Weapon::~Weapon()
{
}

int Weapon::getPierce()
{
  return this->pierce;
}

void Weapon::setPierce(int p)
{
  this->pierce = p;
}

float Weapon::calculateDamage()
{
	int random = rand();

	random = (random % 100) + 1;

	if (float(random) <= this->criticalChance){
		this->wasCrit = true;
		return this->baseDamage * this->criticalDamage;
	}

	this->wasCrit = false;
	return this->baseDamage;
}

bool Weapon::getWasCrit()
{
	return this->wasCrit;
}

bool Weapon::checkAttackTimer(sf::Clock* attackTimer)
{
	if (attackTimer->getElapsedTime() >= this->attackSpeed) {
		attackTimer->restart();
		return true;
	}
	else {
		return false;
	}
}

sf::Texture* Weapon::getBulletTexture() 
{
	return this->defaultBulletTexture;
}

