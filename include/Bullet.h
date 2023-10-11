#ifndef _BULLET_H
#define _BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
private:
	float dano;
	sf::Vector2f direction;

public:
	Bullet(float dano, sf::Texture* texture, sf::Vector2f start_pos);
	~Bullet();

	void setDirection(sf::Vector2f ref_pos);
	void moveDirection();
};

#endif