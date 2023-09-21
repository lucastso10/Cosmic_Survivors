#include "Controller.h"
#include <iostream>

Controller::Controller(Game* game)
{
	this->game = game;
}

Controller::~Controller()
{
}

void Controller::eventHandler()
{
	/*
	* Da poll em todos os eventos da janela,
	* ou seja, fechar janela, apertar tecla,
	* mexer mouse, clickar mouse etc.
	* Tipos de eventos:
	* https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1Event.php#af41fa9ed45c02449030699f671331d4a
	*/
	while(this->game->getEvents(this->event))
	{
		switch (this->event.type)
		{
			// eventos do tipo tecla foi apertada
			case sf::Event::KeyPressed:
				switch (this->event.key.code)
				{
				// tecla direita
					case sf::Keyboard::Right :
						std::cout << "Right key pressed!\n";
						break;	
					default:
						break;
				}
				break;
			// evento para fechar o jogo
			case sf::Event::Closed :
				this->game->quitGame();
				break; 
			default:
				break;
		}
	}
}

void Controller::interpretKey()
{
}
