//#pragma once
#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
private:
	float dano;
	

public:
	Enemy(sf::Sprite, sf::Vector2f);
	~Enemy();

	void attack();
	void goToPlayer();

};

#endif
