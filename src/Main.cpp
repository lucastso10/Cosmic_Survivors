// includes SFML
#include <SFML/Graphics.hpp>
#include <iostream>

// includes locais
#include "Controller.h"
#include "Game.h"
#include "Menu.h"

int main() {
  // a resolução pode ser dinamica no futuro!
  sf::RenderWindow window(sf::VideoMode(1360, 750), "Wipe Out!");
  window.setFramerateLimit(200);

  Game game(&window);
  Menu menu(&game);

  Controller controller(&game, &menu);

  

  // main loop do game!
  while (game.isRunning()) {

    controller.eventHandler();

    if (game.isInMenu()) { // esse if pode ir dentro de updateFrame
        menu.run_menu();
    }
    else{
	game.updateFrame();
    }
  }
  return 0;
}
