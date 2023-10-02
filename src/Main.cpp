// includes SFML
#include <SFML/Graphics.hpp>
#include <iostream>

// includes locais
#include "Controller.h"
#include "Game.h"
#include "Menu.h"

int main() {
  // a resolução pode ser dinamica no futuro!
  sf::RenderWindow window(sf::VideoMode(800, 600), "Wipe Out!");

  Game game(&window);

  Controller controller(&game);

  Menu menu(&game);

  // main loop do game!
  while (game.isRunning()) {

    controller.eventHandler();

    if (game.isInMenu()) {
        menu.run_menu();
    }
    else{game.updateFrame();}
  }
  return 0;
}
