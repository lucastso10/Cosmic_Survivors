#include "Weapon.h"

Weapon::Weapon()
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 0;
	this->armorPenetration = 0;
	this->criticalChance = 0;
	this->criticalDamage = 0;
	this->attackSpeed = 0;

    this->bullets.reserve(100);
}

Weapon::~Weapon()
{
}

float Weapon::calculateDamage()
{
    return 0.0f;
}

void Weapon::shoot(sf::Vector2f direction)
{

}
