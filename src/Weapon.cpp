#include "Weapon.h"

Weapon::Weapon(sf::Texture defaultBulletTexture)
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 0;
	this->armorPenetration = 0;
	this->criticalChance = 0;
	this->criticalDamage = 0;
	this->attackSpeed = 0;

	this->defaultBulletTexture = defaultBulletTexture;

    this->bullets.reserve(100); // não sei se isso é muito ou pouco
	// provavelmente vai trocar
	// essa parte talvez vale a pena ser dinamica
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
	this->bullets.push_back(new Bullet())
}
