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
	switch (this->event.type)
	{
	case sf::Event::KeyPressed:

		switch (this->event.key.code)
		{
		case sf::Keyboard::Right :
			std::cout << "Right key pressed!\n";
			break;	

		}

		break;

	case sf::Event::Closed :
		this->game->quitGame();
		break; 
	default:
		break;
	}
}

void Controller::interpretKey()
{
}
