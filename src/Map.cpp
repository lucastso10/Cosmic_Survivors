#include "Map.h"

Map::Map(std::string file)
{
	//this->texture
}

Map::~Map()
{
}

sf::Vector2f Map::getSize()
{
	return this->size;
}

sf::Texture Map::getTexture()
{
	return this->texture;
}
