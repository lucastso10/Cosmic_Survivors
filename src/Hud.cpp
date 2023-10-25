#include "Hud.h"

Hud::Hud()
{
	hpBarText.loadFromFile("../images/Hud/hpBar.png");
	hpBarSprite.setTexture(hpBarText);

	hpBarSprite.setTextureRect(sf::IntRect(0, 0, 48, 18));
	hpBarSprite.setPosition(sf::Vector2f(5.f, 5.f));
	hpBarSprite.setScale(sf::Vector2f(4, 2));
}

Hud::~Hud()
{
}

void Hud::updateHud(sf::RenderWindow *window, Player player)
{
	if (player.getHealth() <= 75) {
		hpBarSprite.setTextureRect(sf::IntRect(rectLeft, 0, 48, 18));
	}

	if (player.getHealth() <= 50) {
		hpBarSprite.setTextureRect(sf::IntRect(rectLeft*2, 0, 48, 18));
	}

	if (player.getHealth() <= 25) {
		hpBarSprite.setTextureRect(sf::IntRect(rectLeft*3, 0, 48, 18));
	}

	if (player.getHealth() < 1) {
		player.isDead();
	}
	
	window->draw(hpBarSprite);
}
