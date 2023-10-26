#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2f start_pos)
{
	this->animationClock.restart();

	// A extura da arma pode ser só uma que é 
	// carregada várias vezes por várias instacias 
	// de Bullet
	this->setTexture(texture);

	sf::Sprite sprite;
	sprite.setTexture(*texture);

	this->setSprite(sprite);
	this->setPos(start_pos);
	this->setTextureSpriteRect(sf::IntRect(0, 0, 16, 16)); // assume que utiliza uma textura 16x16 do pacote de textura all fire bullet pixels
	this->setScale(sf::Vector2f(2, 2));
	this->adjustOrigin();
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
	sf::IntRect newRect = this->getTextureSpriteRect();

	if (this->animationClock.getElapsedTime() >= sf::milliseconds(150)) {
		if (newRect.left == 48 )
			newRect.left = 0;
		else
			newRect.left += 16;
		this->animationClock.restart();
	}

	this->setTextureSpriteRect(newRect);
	this->move(this->direction);
}