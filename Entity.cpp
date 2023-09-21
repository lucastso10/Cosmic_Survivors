#include "Entity.h"

Entity::Entity(sf::Sprite sprite, bool stationary)
{
	//this->sprite = sprite;
	//this->stationary = stationary;
}

Entity::~Entity()
{
}

bool Entity::isOnScreen()
{
    return false;
}

void Entity::move(sf::Vector2f direction)
{
	//this->sprite.move(direction);
}

void Entity::onDeath()
{
}

bool Entity::isDead()
{
	return this->health <= 0;
}
