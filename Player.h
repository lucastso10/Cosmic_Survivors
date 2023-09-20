#pragma once
#include "Entity.h"
#include "Weapon.h"

class Player : public Entity , public Weapon
{
public:
	void levelUp();

private:
	int xp;
	int level;
	Weapon weapon;
};

