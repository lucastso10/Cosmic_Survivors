#include "Map.h"

Map::Map(std::string arquivo)
{
	sf::Texture* texture = new sf::Texture;
	sf::Sprite sprite;
	texture->loadFromFile(arquivo);
	sprite.setTexture(*texture);

	this->texture = texture;
	this->sprite = sprite;
}

Map::~Map()
{
}

void Map::drawMap(sf::RenderWindow* render)
{
	render->draw(this->sprite);
}
