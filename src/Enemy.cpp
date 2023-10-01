#include "Enemy.h"

Enemy::Enemy(std::string arquivo, sf::Vector2f pos) {
	this->dano = 0.0;
	this->Pos = pos;

	sf::Texture* enemyTexture = new sf::Texture;
	sf::Sprite enemySprite;

	enemyTexture->loadFromFile(arquivo);
	enemySprite.setTexture(*enemyTexture);

	this->setTexture(enemyTexture);
	this->setSprite(enemySprite);
	this->setPos(pos);
}

Enemy::~Enemy() {

}

void Enemy::attack()
{
}

void Enemy::goToPlayer(sf::Vector2f currentPlayerPos)
{
	this->move(sf::Vector2f(0.1,0.1));
}
