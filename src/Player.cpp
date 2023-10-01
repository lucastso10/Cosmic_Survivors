#include "Player.h"

Player::Player(std::string file, sf::Vector2f start_pos)
{
	this->xp = 0;
	this->level = 0;
	//this->weapon = 

	sf::Texture* texture = new sf::Texture;
	sf::Sprite sprite;

	texture->loadFromFile(file, sf::IntRect(14, 1, 23, 23));
	sprite.setTexture(*texture);
	

	this->setTexture(texture);
	this->setSprite(sprite);
	this->setPos(start_pos);
}

Player::~Player()
{
}

void Player::levelUp()
{	
}
