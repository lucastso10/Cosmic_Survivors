#include "Hud.h"
#include <iostream>

Hud::Hud()
{
	hpBarText.loadFromFile("../images/Hud/hpBar.png");
	hpBarSprite.setTexture(hpBarText);
	hpBarSprite.setTextureRect(sf::IntRect(0, 0, 48, 18));
	hpBarSprite.setPosition(sf::Vector2f(5.f, 5.f));
	hpBarSprite.setScale(sf::Vector2f(4, 2));

	xpBarText.loadFromFile("../images/Hud/xpBar.png");
	xpBarSprite.setTexture(xpBarText);
	xpBarSprite.setTextureRect(sf::IntRect(0, 0, 48, 18));
	xpBarSprite.setPosition(sf::Vector2f(5.f, 50.f));
	xpBarSprite.setScale(sf::Vector2f(4, 2));

	font.loadFromFile("../fonte/kenneypixel.ttf");
	fpsClock.restart();

	fpsCounter = 0;

	fps.setFont(this->font);
	fps.setFillColor(sf::Color::White);
	fps.setOutlineColor(sf::Color::Black);
	fps.setOutlineThickness(1.f);
	fps.setPosition({1320, -10});

	level.setFont(this->font);
	level.setFillColor(sf::Color::Magenta);
	level.setOutlineColor(sf::Color::White);
	level.setOutlineThickness(1.f);
	level.setPosition({200, 45});

}

Hud::~Hud()
{
}

sf::Sprite Hud::updateHpBar(Player* player)
{
	if (player->getHealth() <= 75) {
		hpBarSprite.setTextureRect(sf::IntRect(spriteIncrement, 0, 48, 18));
	}

	if (player->getHealth() <= 50) {
		hpBarSprite.setTextureRect(sf::IntRect(spriteIncrement * 2, 0, 48, 18));
	}

	if (player->getHealth() <= 25) {
		hpBarSprite.setTextureRect(sf::IntRect(spriteIncrement * 3, 0, 48, 18));
	}

	if (player->getHealth() < 1) {
		hpBarSprite.setTextureRect(sf::IntRect(spriteIncrement * 4, 0, 48, 18));
		player->isDead();
	}
	
	return hpBarSprite;
}

sf::Sprite Hud::updateXpBar(Player* player) {

	if (player->getXp() <= 75) {
		xpBarSprite.setTextureRect(sf::IntRect(spriteIncrement, 0, 48, 18));
	}

	if (player->getXp() <= 50) {
		xpBarSprite.setTextureRect(sf::IntRect(spriteIncrement * 2, 0, 48, 18));
	}

	if (player->getXp() <= 25) {
		xpBarSprite.setTextureRect(sf::IntRect(spriteIncrement * 3, 0, 48, 18));
	}

	if (player->getXp() < 1) {
		xpBarSprite.setTextureRect(sf::IntRect(spriteIncrement * 4, 0, 48, 18));
	}

	return xpBarSprite;
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

sf::Text Hud::updateLevel(Player* player) {
	level.setString(std::to_string(player->getLevel()));
	return level;
}