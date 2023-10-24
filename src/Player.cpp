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

void Player::iniFont()
{
}

void Player::initHpBar()
{
	this->hpBar.setSize(sf::Vector2f(250.f, 25.f));
	this->hpBar.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBar.setPosition(sf::Vector2f(10.f, 10.f));

	this->hpBarInside.setSize(sf::Vector2f(250.f, 25.f));
	this->hpBarInside.setFillColor(sf::Color(250, 20, 20, 200));
	this->hpBarInside.setPosition(this->hpBar.getPosition());
}

void Player::updateHpBar()
{
}

void Player::renderHpBar(sf::RenderTarget &target)
{
	target.draw(this->hpBar);
	target.draw(this->hpBarInside);
}

void Player::render(sf::RenderWindow* window) {
	this->initHpBar();
	this->renderHpBar(*window);
}