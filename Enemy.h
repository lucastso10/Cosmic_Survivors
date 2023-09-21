//#pragma once
#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
private:
	float dano;

public:
	void attack();
	void goToPlayer();

};

#endif
