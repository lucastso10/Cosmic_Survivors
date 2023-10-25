#include "Player.h"

Player::Player(std::string file, sf::Texture* bulletTexture, sf::Vector2f start_pos)
{
	this->xp = 0;
	this->level = 0;
	this->weapon = new Weapon(bulletTexture); // solução temporaria
	// acho que o melhor jeito de fazer isso seria
	// um Enum com o tipo de cada arma
	// ai usuario decide a arma que quer usar no menu
	// e dependendo do enum que selecionar ele da fetch
	// na textura das balas e todas as caracteristicas da arma

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

void Player::attack(sf::Vector2f direction)
{
	this->weapon->shoot(direction, this->getPos());
}

void Player::drawBullets(sf::RenderWindow* render)
{
	this->weapon->drawBullets(render);
}

bool Player::checkAttackTimer(sf::Clock* attackTimer)
{
	return this->weapon->checkAttackTimer(attackTimer);
}