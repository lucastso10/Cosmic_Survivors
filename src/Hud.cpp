#include "Hud.h"
#include <iostream>

Hud::Hud()
{
	hpBarText.loadFromFile("../images/Hud/hpBar.png");
	hpBarSprite.setTexture(hpBarText);

	hpBarSprite.setTextureRect(sf::IntRect(0, 0, 48, 18));
	hpBarSprite.setPosition(sf::Vector2f(5.f, 5.f));
	hpBarSprite.setScale(sf::Vector2f(4, 2));

	
	font.loadFromFile("../fonte/kenneypixel.ttf");
	fpsClock.restart();

	fpsCounter = 0;

	fps.setFont(this->font);
	fps.setFillColor(sf::Color::White);
	fps.setOutlineColor(sf::Color::Black);
	fps.setOutlineThickness(1.f);
	fps.setPosition({1320, -10});
}

Hud::~Hud()
{
}

sf::Sprite Hud::updateHpBar(Player* player)
{
	if (player->getHealth() <= 75) {
		hpBarSprite.setTextureRect(sf::IntRect(rectLeft, 0, 48, 18));
	}

	if (player->getHealth() <= 50) {
		hpBarSprite.setTextureRect(sf::IntRect(rectLeft*2, 0, 48, 18));
	}

	if (player->getHealth() <= 25) {
		hpBarSprite.setTextureRect(sf::IntRect(rectLeft*3, 0, 48, 18));
	}

	if (player->getHealth() < 1) {
		player->isDead();
	}
	
	return hpBarSprite;
}

sf::Text Hud::updateFPS()
{
	fpsCounter++;	
	if (fpsClock.getElapsedTime().asSeconds() >= 1.f)
	{
		fps.setString(std::to_string(this->fpsCounter));

		fpsCounter = 0;
		fpsClock.restart();
	}
	return fps;
}
