// includes SFML
#include <SFML/Graphics.hpp>
#include <iostream>

// includes locais
#include "Controller.h"
#include "Game.h"

int main() {
  // a resolução pode ser dinamica no futuro!
  sf::RenderWindow window(sf::VideoMode(800, 600), "Wipe Out!");

  Game game(&window);

  Controller controller(&game);

  game.startGame();

  // main loop do game!
  while (game.isRunning()) {

    controller.eventHandler();

    game.updateFrame();
  }
  return 0;
}
