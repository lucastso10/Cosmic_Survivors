#include "Enemy.h"

Enemy::Enemy(std::string arquivo, sf::Vector2f pos) {
	this->dano = 0.0;
	this->armor = 0.0;
	this->health = 10.0;
	this->speed = 25.0f;
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

	sf::Vector2f enemyToPlayer = currentPlayerPos - this->getPos();
	float distanceToPlayer = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);
	
	sf::Vector2f movementDirection = enemyToPlayer / distanceToPlayer;
	this->move(movementDirection/this->speed);
	
}
