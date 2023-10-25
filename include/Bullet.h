#ifndef _BULLET_H
#define _BULLET_H

#include "Entity.h"
#include "Enemy.h"

class Bullet : public Entity
{
private:
	sf::Vector2f direction;

public:
	Bullet(sf::Texture* texture, sf::Vector2f start_pos);
	~Bullet();

	void checarHit(Enemy* enemy);
	void setDirection(sf::Vector2f ref_pos);
	void moveDirection();
};

#endif