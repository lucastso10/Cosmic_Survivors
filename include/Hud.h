//#pragma once
#ifndef _HUD_H
#define _HUD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"

class Hud
{
private:
	int spriteIncrement = 48;

	sf::Texture hpBarText;
	sf::Sprite hpBarSprite;

	sf::Texture xpBarText;
	sf::Sprite xpBarSprite;

	sf::Clock fpsClock;
	int fpsCounter;
	sf::Text fps;
	sf::Font font;

	sf::Text level;
	
public:
	Hud();
	~Hud();

	sf::Text updateFPS();
	sf::Text updateLevel(Player* player);

	sf::Sprite updateHpBar(Player* player);
	sf::Sprite updateXpBar(Player* player);

};

#endif
