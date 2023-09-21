#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	this->renderWindow = window;
	this->running = true;
}

Game::~Game()
{
}

bool Game::getEvents(sf::Event &event)
{
	return this->renderWindow->pollEvent(event);
}

void Game::updateFrame()
{
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
