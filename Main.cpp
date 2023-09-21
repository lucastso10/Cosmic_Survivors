// includes SFML
#include <SFML/Graphics.hpp>
#include <iostream>

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
