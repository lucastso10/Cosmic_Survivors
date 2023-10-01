#include "Enemy.h"

Enemy::Enemy(sf::Sprite sprite, sf::Vector2f vec) {
	this->setSprite(sprite);
	this->setPos(vec);
	this->dano = 0.0;
}

Enemy::~Enemy() {

}

void Enemy::attack()
{
}

void Enemy::goToPlayer()
{
}
