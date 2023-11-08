#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
	float damage;

public:
	Enemy(std::string);
	~Enemy();

	void attack(Player* player);
	void goToPlayer(sf::Vector2f currentPlayerPos, std::vector<Enemy*>& enemies);
	
	bool checkCollision(const Enemy& enemy);
	void enemySpawn();

	//sf::Vector2f teste(sf::Vector2f);
};

#endif
