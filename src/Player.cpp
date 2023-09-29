#include "Player.h"

Player::Player(sf::Sprite sprite, sf::Vector2f start_pos)
{
	this->xp = 0;
	this->level = 0;
	//this->weapon = 
	
	this->setSprite(sprite);
	this->setPos(start_pos);
}

Player::~Player()
{
}

void Player::levelUp()
{	
}
