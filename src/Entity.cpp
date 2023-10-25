#include "Entity.h"

bool Entity::isOnScreen()
{
    return false;
}

void Entity::setPos(sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

sf::Vector2f Entity::getPos()
{
	return sprite.getPosition();
}

void Entity::setSprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

sf::Sprite Entity::getSprite()
{
	return this->sprite;
}

void Entity::setTexture(sf::Texture* texture)
{
	this->texture = texture;
}

void Entity::setTextureSpriteRect(sf::IntRect rect)
{
	this->sprite.setTextureRect(rect);
}

sf::IntRect Entity::getTextureSpriteRect()
{
	return this->sprite.getTextureRect();
}

void Entity::adjustOrigin()
{
	this->sprite.setOrigin((this->sprite.getLocalBounds().getSize() / 2.0f));
}

void Entity::move(sf::Vector2f direction)
{
	this->sprite.move(direction);
}

void Entity::onDeath() // isso pode ser especifico de cada tipo de entidade
{
}

bool Entity::isDead()
{
	return this->health <= 0;
}
