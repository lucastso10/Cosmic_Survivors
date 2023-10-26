#include "Player.h"
#include <iostream>
Player::Player(std::string file, sf::Vector2f start_pos)
{
	this->setHealth(100);
	this->setArmor(20);
	this->setSpeed(2);

	this->xp = 0;
	this->level = 0;
	this->isWalking = false;
	
	sf::Texture* texture = new sf::Texture;
	sf::Sprite sprite;

	texture->loadFromFile(file, sf::IntRect(12, 0, 26, 26));
	sprite.setTexture(*texture);

	this->setTexture(texture);
	this->setSprite(sprite);
	this->setPos(start_pos);
	this->setScale(sf::Vector2f(1.5f, 1.5f));
	this->animationClock.restart();
	this->adjustOrigin();
	
}

Player::~Player()
{
}

void Player::setWalking(bool walking)
{
	this->isWalking = walking;
}

void Player::animate()
{
	sf::IntRect newRect = this->getTextureSpriteRect();

	if (this->animationClock.getElapsedTime() >= sf::milliseconds(150)) {
		if (newRect.left == 48)
			newRect.left = 0;
		else
			newRect.left += 16;
		this->animationClock.restart();
	}

	this->setTextureSpriteRect(newRect);
}

void Player::levelUp()
{	
}

