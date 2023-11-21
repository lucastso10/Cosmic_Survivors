#include "Weapon.h"

Weapon::Weapon(sf::Texture* defaultBulletTexture)
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 10.0;
	this->armorPenetration = 0;
	this->criticalChance = 0;
	this->criticalDamage = 0;
	this->attackSpeed = sf::seconds(1.0f);
	this->pierce = 1;

	this->defaultBulletTexture = defaultBulletTexture;


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
	return this->baseDamage;
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

