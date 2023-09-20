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
}

bool Game::isRunning()
{
	return this->running;
}
