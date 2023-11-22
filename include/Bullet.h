#ifndef _BULLET_H
#define _BULLET_H

#include "Entity.h"


class Bullet : public Entity
{
private:
	sf::Vector2f direction;
	sf::Text damageNumber;
	sf::Font font;
	bool drawingText;
	sf::Clock textClock;

public:
	Bullet(sf::Texture* texture);
	~Bullet();

	int enemiesHit;
	sf::Text drawDamage(int damage, bool crit);
	sf::Text drawDamage();
	//void checarHit();
	void setDirection(sf::Vector2f ref_pos);
	void moveDirection();
	bool getDrawingText();
};

#endif
