#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
	float damage;

public:
	Enemy(sf::Texture*);
	~Enemy();

	void attack(Player* player);
	void goToPlayer(sf::Vector2f currentPlayerPos, std::vector<Enemy*>& enemies);
	
	bool checkCollision(const Enemy& enemy);
	void spawn(sf::RenderWindow* window);

	//sf::Vector2f teste(sf::Vector2f);
};

#endif
