#include "Game.h"

Game::Game()
{
	this->running = false;
}

Game::~Game()
{
	delete this->renderWindow;
	delete this->vectorEntities;
	delete this->controller;
	delete this->event;
}

void Game::updateFrame()
{
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
