#include "Bullet.h"

Bullet::Bullet(float dano, sf::Texture* texture, sf::Vector2f start_pos)
{
	this->dano = dano;
	this->animationFrameCount = 0;

	// A extura da arma pode ser só uma que é 
	// carregada várias vezes por várias instacias 
	// de Bullet
	this->setTexture(texture);

	sf::Sprite sprite;
	sprite.setTexture(*texture);

	this->setSprite(sprite);
	this->setPos(start_pos);
	this->setTextureSpriteRect(sf::IntRect(0, 0, 16, 16)); // assume que utiliza uma textura 16x16 do pacote de textura all fire bullet pixels
}

Bullet::~Bullet()
{
	delete this;
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

	if (this->animationFrameCount >= 5) {
		if (newRect.left == 64)
			newRect.left = 0;
		else
			newRect.left += 16;
		this->animationFrameCount = 0;
	}
	this->animationFrameCount++;

	this->setTextureSpriteRect(newRect);
	this->move(this->direction);
}