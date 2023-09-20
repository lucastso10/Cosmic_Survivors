#pragma once
class Map
{
private:
	sf::Vector2f size;

	sf::Texture texture;

public:

	Map(string file);
	~Map();

	sf::Vector2f getSize();

	sf::Texture getTexture();

};

