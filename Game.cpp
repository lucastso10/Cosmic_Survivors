#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow* window)
{
	this->renderWindow = window;
	this->running = true;
}

Game::~Game()
{
}

void Game::updateFrame()
{
	while(this->renderWindow->pollEvent(this->event))
	{
		if(this->event.type == sf::Event::Closed){
			this->renderWindow->close();
			this->quitGame();
		}
	}

	this->renderWindow->display();
}

void Game::startGame()
{
}

void Game::pauseGame()
{
}

void Game::quitGame()
{
	this->running = false;
}

bool Game::isRunning()
{
	return this->running;
}
