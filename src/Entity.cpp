#include "Entity.h"
#include <iostream>
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

void Entity::setStationary(bool stat)
{
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

float Entity::getHealth() {
	return this->health;
}

float Entity::getArmor() {
	return this->armor;
}

float Entity::getSpeed() {
	return this->speed;
}

void Entity::setHealth(float health) 
{
	this->health = health;
}

void Entity::setArmor(float armor) 
{
	this->armor = armor;
}

void Entity::setSpeed(float speed) 
{
	this->speed = speed;
}

void Entity::setScale(sf::Vector2f scale)
{
	this->sprite.setScale(scale);
}

void Entity::flip()
{
	this->sprite.setScale(this->sprite.getScale().x * -1, this->sprite.getScale().y);
}