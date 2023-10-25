#include "Weapon.h"

Weapon::Weapon(sf::Texture* defaultBulletTexture)
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 1.0;
	this->armorPenetration = 0;
	this->criticalChance = 0;
	this->criticalDamage = 0;
	this->attackSpeed = sf::seconds(1.0f);

	this->defaultBulletTexture = defaultBulletTexture;

}

Weapon::~Weapon()
{
}

float Weapon::calculateDamage()
{
    return 0.0f;
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
