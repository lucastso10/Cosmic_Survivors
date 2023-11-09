//#pragma once
#ifndef _HUD_H
#define _HUD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"

class Hud
{
private:
	sf::Texture hpBarText;
	sf::Sprite hpBarSprite;
	int rectLeft = 48;

	sf::Clock fpsClock;
	int fpsCounter;
	sf::Text fps;
	sf::Font font;
	
public:
	Hud();
	~Hud();

	sf::Text updateFPS();
	sf::Sprite updateHpBar(Player* player);


};

#endif
