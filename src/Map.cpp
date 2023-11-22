#include "Map.h"

Map::Map()
{
	sf::Texture* texture = new sf::Texture;
	sf::Sprite sprite;
	texture->loadFromFile("../images/map/tileset.png");
	sprite.setTexture(*texture);
	this->mapTexture = texture;
	this->mapSprite = sprite;

	this->mapSprite.setPosition(0,0);
	
	sf::Texture* backtexture = new sf::Texture;
	sf::Sprite backsprite;
	backtexture->loadFromFile("../images/map/background.png");
	backsprite.setTexture(*backtexture);
	this->backgroundTexture = backtexture;
	this->backgroundSprite = backsprite;

	this->backgroundSprite.setPosition(0,0);
}

Map::~Map()
{
}

void Map::drawMap(sf::RenderWindow* render)
{
	render->draw(this->mapSprite);
}

void Map::drawBackground(sf::RenderWindow* render)
{
	render->draw(this->backgroundSprite);
}
