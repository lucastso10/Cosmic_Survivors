#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	void attack();
	void goToPlayer();
private:
	float dano;

};

