#include "Enemy.h"
#include <math.h>

Enemy::Enemy(sf::Texture* enemyTexture, bool boss) {
	this->damage = 0.1;
	this->health = 0.0;


	sf::Sprite enemySprite;
	enemySprite.setTexture(*enemyTexture);
	if (boss){
		enemySprite.setTextureRect(sf::IntRect(32, 19, 49, 66));
		this->setSprite(enemySprite);
		this->setSpeed(0.5f); // 0.5f
		this->setScale(sf::Vector2f(1.5f, 1.5f));
	}else{
		enemySprite.setTextureRect(sf::IntRect(16, 16, 16, 24)); // 10, 4, 12, 22
		this->setSprite(enemySprite);
		this->setSpeed(0.7f); // 0.5f
		this->setScale(sf::Vector2f(1.7f, 1.7f));
	}
	this->side = 1;
	this->adjustOrigin();
}

Enemy::~Enemy()
{
}

void Enemy::attack(Player* player)
{
	player->setHealth(player->getHealth() - this->damage);
}

void Enemy::goToPlayer(sf::Vector2f currentPlayerPos, sf::Vector2i enemyScreenPos, bool boss)
{
	sf::IntRect newRect = this->getTextureSpriteRect();

	if(boss){
		if (this->animationClock.getElapsedTime() >= sf::milliseconds(150)) {
			if (newRect.left == 332)
				newRect.left = 32;
			else
				newRect.left += 100;

			this->animationClock.restart();
		}
	} else {
		if (this->animationClock.getElapsedTime() >= sf::milliseconds(400)) {
			if (newRect.left == 166)
				newRect.left = 16;
			else
				newRect.left += 50;
			this->animationClock.restart();
		}
	}

	if (side == 1 && enemyScreenPos.x > 680){
		this->flip();
		side = 0;
	} else if (side == 0 && enemyScreenPos.x < 680){
		this->flip();
		side = 1;
	}

	sf::Vector2f enemyToPlayer = currentPlayerPos - this->getPos();
	float distanceToPlayer = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);

	sf::Vector2f movementDirection = enemyToPlayer / distanceToPlayer;

	this->setTextureSpriteRect(newRect);
	this->move(movementDirection * this->getSpeed());

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

void Enemy::spawn(sf::RenderWindow* window)
{
	this->health = 20.0;
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
