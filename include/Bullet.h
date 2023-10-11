#ifndef _BULLET_H
#define _BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
private:
	float dano;

public:
	Bullet(float dano, sf::Texture* texture, sf::Vector2f start_pos);
	~Bullet();
};

#endif