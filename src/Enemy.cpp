#include "Enemy.h"
#include <iostream>

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
	
	float diferencax = currentPlayerPos.x - this->Pos.x;
	float diferencay = currentPlayerPos.y - this->Pos.y;

	float diag = std::sqrt((diferencax * diferencax) + (diferencay * diferencay));

	diferencax /= diag;
	diferencay /= diag;

	this->move(sf::Vector2f(diferencax/100, diferencay/100));

}

//sf::Vector2f Enemy::teste(sf::Vector2f currentPlayerPos) {
//	float route = sqrt((currentPlayerPos.x * currentPlayerPos.x) + (currentPlayerPos.y * currentPlayerPos.y));
//	if (route != 0) {
//		this->move(sf::Vector2f((currentPlayerPos.x / route)/100, (currentPlayerPos.y / route)/100));
//		return sf::Vector2f();
//	}
//	else
//		this->move(sf::Vector2f((currentPlayerPos.x / route) / 10, (currentPlayerPos.y / route) / 10));
//		return currentPlayerPos;
//}
