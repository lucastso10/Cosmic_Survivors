#pragma once
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

