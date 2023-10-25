#include "Player.h"
#include <iostream>
Player::Player(std::string file, sf::Vector2f start_pos)
{
	this->setHealth(100);
	this->setArmor(20);
	this->setSpeed(2);

	this->xp = 0;
	this->level = 0;
	
	sf::Texture* texture = new sf::Texture;
	sf::Sprite sprite;

	texture->loadFromFile(file, sf::IntRect(14, 1, 23, 23));
	sprite.setTexture(*texture);

	this->setTexture(texture);
	this->setSprite(sprite);
	this->setPos(start_pos);
	this->adjustOrigin();
	
}

Player::~Player()
{
}

void Player::levelUp()
{	
}

