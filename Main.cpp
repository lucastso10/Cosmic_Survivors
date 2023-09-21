// includes SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

// includes locais
#include "Game.h"
#include "Controller.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Wipe Out!");

	Game game(&window);
	
	Controller controller(&game);

	while(game.isRunning()){

		controller.eventHandler();

		game.updateFrame();
	}

    return 0;
}
