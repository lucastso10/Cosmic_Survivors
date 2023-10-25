#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
	float dano;
	sf::Vector2f Pos;


public:
	Enemy(std::string, sf::Vector2f);
	~Enemy();

	void attack(Player* player);
	void goToPlayer(sf::Vector2f);
	
	//sf::Vector2f teste(sf::Vector2f);
};

#endif
