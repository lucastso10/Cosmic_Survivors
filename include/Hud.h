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
	
public:
	Hud();
	~Hud();

	void updateHud(sf::RenderWindow* window, Player player);


};

#endif
