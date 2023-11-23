#include "Weapon.h"
#include <iostream>
#include <math.h>

Weapon::Weapon(sf::Texture* defaultBulletTexture)
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 10.0;
	this->criticalChance = 50; // número em porcentagem por exemplo 25,5 pra 25,5% de chance
	this->criticalDamage = 2;
	this->attackSpeed = sf::seconds(1.0f);
	this->pierce = 1;

	this->type = SIMPLE;

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

void Weapon::attack(std::vector<Bullet*> bullets, sf::Vector2f playerPos, sf::Vector2f mousePos)
{
	if (this->type == SIMPLE){
		for (auto& bullet : bullets) {
			if (!(bullet->isDead()))
				continue;

			bullet->setHealth(1.f);
			bullet->setPos(playerPos);
			bullet->setDirection(mousePos);
			break;
		}
	} else if (this->type == SHOTGUN){
		int count = 0;
		for (auto& bullet : bullets){
			if (!(bullet->isDead()))
				continue;

			bullet->setHealth(1.f);
			bullet->setPos(playerPos);
			switch (count) {
				case 0:
					bullet->setDirection(mousePos - sf::Vector2f(75.f, 75.f));
					break;
				case 1:
					bullet->setDirection(mousePos);
					break;
				case 2:
					bullet->setDirection(mousePos + sf::Vector2f(75.f, 75.f));
					break;
			}
			count++;
			if (count == 3)
				break;
		}
	} else if (this->type == SPREAD){
		int count = 0;
		for (auto& bullet : bullets){
			if (!(bullet->isDead()))
				continue;

			bullet->setHealth(1.f);
			bullet->setPos(playerPos);
			switch (count) {
				case 0:
					bullet->setDirection(mousePos - sf::Vector2f(75.f, 75.f));
					break;
				case 1:
					bullet->setDirection(mousePos);
					break;
				case 2:
					bullet->setDirection(mousePos + sf::Vector2f(75.f, 75.f));
					break;
			}
			count++;
			if (count == 3)
				break;
		}

	}
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

