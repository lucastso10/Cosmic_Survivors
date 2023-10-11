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
