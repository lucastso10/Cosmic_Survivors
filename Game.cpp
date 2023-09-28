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

// todos o que vai ser desenhado na tela precisa acontecer aqui
void Game::updateFrame()
{
	this->renderWindow->display();
}


void Game::startGame()
{
	Player p = new Player;
	this->player = p;
}

// talvez criar um booleano para checar se o jogo está pausado?
void Game::pauseGame()
{
}

// precisa limpar a memoria antes
void Game::quitGame()
{
	this->running = false;
}

bool Game::isRunning()
{
	return this->running;
}
