#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
	float damage;

	int side; // 0 = esquerda 1 = direita

public:
	Enemy(sf::Texture*, bool);
	~Enemy();

	void attack(Player* player);
	void goToPlayer(sf::Vector2f currentPlayerPos, sf::Vector2i enemyScreenPos, bool boss);
	
	bool checkCollision(const Enemy& enemy);
	void spawn(sf::RenderWindow* window);

	//sf::Vector2f teste(sf::Vector2f);
};

#endif
