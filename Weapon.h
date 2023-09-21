//#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon 
{
public:
	float calculateDamage();
	void attack();

private:
	float baseDamage;
	float armorPenetration;
	float criticalChance;
	float criticalDamage;
	float attackSpeed;

};

#endif