#include "Enemy.h"
#include <math.h>

Enemy::Enemy(sf::Texture* enemyTexture) {
	this->damage = 0.001;
	this->armor = 0.0;
	this->health = 1.0;

	sf::Sprite enemySprite;

	enemySprite.setTexture(*enemyTexture);
	enemySprite.setTextureRect(sf::IntRect(10, 4, 12, 22));
	this->setSpeed(0.5f);
	this->setTexture(enemyTexture);
	this->setSprite(enemySprite);
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
	this->move(movementDirection);

	//Checa colisao de inimigos NAO FUNCIONA LEGAL

	/*
	for (auto& enemy : enemies) {
		if (this->getSprite().getGlobalBounds() == enemy->getSprite().getGlobalBounds())
			continue;

		if (this->checkCollision(*enemy)) {
			this->move((movementDirection * this->speed) * -1.f);
		}
	}
	*/


}

bool Enemy::checkCollision(const Enemy& enemy)
{
	return this->sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds());
}

void Enemy::enemySpawn(sf::RenderWindow* window)
{
	int random = rand();
	float x, y;

	if (random % 2 == 0) {
		random = rand();
		if (random % 2 == 0) {
			x = (random % (0 - 100) + 100) * (-1);
			y = (rand() % 850) - 100;
		}
		else {
			x = (random % (1360 - 1460) + 1460);
			y = (rand() % 850) - 100;
		}
	}
	else {
		random = rand();
		if (random % 2 == 0) {
			x = (rand() % 1460) - 100;
			y = (random % (0 - 100) + 100) * (-1);
		}
		else {
			x = (rand() % 1460) - 100;
			y = (random % (750 - 850) + 850);
		}
	}
	this->setPos(window->mapPixelToCoords(sf::Vector2i(x, y)));
}
