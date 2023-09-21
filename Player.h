#pragma once
#include "Entity.h"
#include "Weapon.h"

class Player : public Entity
{
public:
	void levelUp();

private:
	int xp;
	int level;
	Weapon weapon;
};

