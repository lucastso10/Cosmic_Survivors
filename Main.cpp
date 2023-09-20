// includes SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

// includes locais
#include "Game.cpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Wipe Out!");

	Game game(&window);

	while(game.isRunning()){

		game.updateFrame();
	}

    return 0;
}
