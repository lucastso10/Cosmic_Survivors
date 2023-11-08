#include "Enemy.h"
#include <math.h>

Enemy::Enemy(std::string arquivo, sf::Vector2f pos) {
	this->damage = 0.001;
	this->armor = 0.0;
	this->health = 15.0;
	this->speed = 100.0f;

	sf::Texture* enemyTexture = new sf::Texture;
	sf::Sprite enemySprite;

	enemyTexture->loadFromFile(arquivo);
	enemySprite.setTexture(*enemyTexture);
	enemySprite.setTextureRect(sf::IntRect(10, 4, 12, 22));

	this->setTexture(enemyTexture);
	this->setSprite(enemySprite);
	this->setPos(pos);
	this->adjustOrigin();
}

Enemy::~Enemy()
{

}

void Enemy::attack(Player* player)
{
	player->setHealth(player->getHealth() - this->damage);
}

void Enemy::goToPlayer(sf::Vector2f currentPlayerPos, std::vector<Enemy*>& enemies)
{

	sf::Vector2f enemyToPlayer = currentPlayerPos - this->getPos();
	float distanceToPlayer = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);

	sf::Vector2f movementDirection = enemyToPlayer / distanceToPlayer;
	this->move(movementDirection / this->speed);

	//Checa colisao de inimigos 

	for (auto& enemy : enemies) {
		if (this->getSprite().getGlobalBounds() == enemy->getSprite().getGlobalBounds())
			continue;

		if (this->checkCollision(*enemy)) {
			this->move((movementDirection / this->speed) * -1.f);
		}
	}


}

bool Enemy::checkCollision(const Enemy& enemy)
{
	return this->sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds());
}
