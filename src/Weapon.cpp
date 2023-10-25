#include "Weapon.h"

Weapon::Weapon(sf::Texture* defaultBulletTexture)
{
	// esses status podem trocar dependendo do tipo de arma
	// que o usuario escolher
	this->baseDamage = 0;
	this->armorPenetration = 0;
	this->criticalChance = 0;
	this->criticalDamage = 0;
	this->attackSpeed = sf::seconds(1.0f);

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

void Weapon::shoot(sf::Vector2f direction, sf::Vector2f start_pos)
{
	Bullet* b = new Bullet(0.0f, this->defaultBulletTexture, start_pos);
	b->setDirection(direction);

	this->bullets.push_back(b);
}

void Weapon::drawBullets(sf::RenderWindow* render)
{
	if (!bullets.empty()) {
		for (auto& bullet : this->bullets) {
			render->draw(bullet->getSprite());
			bullet->moveDirection();
		}
	}
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
