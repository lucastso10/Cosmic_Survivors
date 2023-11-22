#ifndef _BULLET_H
#define _BULLET_H

#include "Entity.h"


class Bullet : public Entity
{
private:
	sf::Vector2f direction;
	sf::Text damageNumber;
	sf::Font font;

public:
	Bullet(sf::Texture* texture);
	~Bullet();

	int enemiesHit;
	sf::Text drawDamage(int damage, sf::Vector2f position);
	//void checarHit();
	void setDirection(sf::Vector2f ref_pos);
	void moveDirection();
};

#endif
