#include "Bullet.h"

Bullet::Bullet(float dano, sf::Texture* texture, sf::Vector2f start_pos)
{
	this->dano = dano;

	// A extura da arma pode ser só uma que é 
	// carregada várias vezes por várias instacias 
	// de Bullet
	this->setTexture(texture);

	sf::Sprite sprite;
	sprite.setTexture(*texture);

	this->setSprite(sprite);
	this->setPos(start_pos);
}

Bullet::~Bullet()
{
}

void Bullet::setDirection(sf::Vector2f ref_pos)
{
	sf::Vector2f enemyToPlayer = ref_pos - this->getPos();
	float distanceToPlayer = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);

	sf::Vector2f movementDirection = enemyToPlayer / distanceToPlayer;
	this->direction = (movementDirection / 25.0f);
}

void Bullet::moveDirection()
{
	this->move(this->direction);
}