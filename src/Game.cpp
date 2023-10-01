#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	this->player = nullptr; // o jogador s� � carregado quando o jogo inicia
	this->renderWindow = window;
	this->running = true;
	this->inMenu = true;
	this->Enemies.reserve(5); // vetor come�a vazio e reserva espa�o para 500 ponteiros

}

Game::~Game()
{
}

bool Game::getEvents(sf::Event &event)
{
	return this->renderWindow->pollEvent(event);
}

bool Game::isInMenu()
{
	return this->inMenu;
}

void Game::movePlayer(sf::Vector2f dist)
{
	return this->player->move(dist);
}

// todos o que vai ser desenhado na tela precisa acontecer aqui
void Game::updateFrame()
{
	if(this->isInMenu())
	{

	}
	else {
		this->renderWindow->clear(sf::Color::Black);
		this->renderWindow->draw(this->player->getSprite());
		
		if (!Enemies.empty()) {
			for (int i = 0; i < Enemies.size(); i++){ 
				this->renderWindow->draw(this->Enemies[i]->getSprite());
				Enemies[i]->goToPlayer(this->player->getPos());
				
				
			}
			
		}
	}
	this->renderWindow->display();
}


void Game::startGame()
{
	this->inMenu = false;
	Player* p = new Player("../images/Peter_Griffin.png", sf::Vector2f(200.0f, 150.0f));
	this->player = p;
	

	for (int i = 0; i < 5; i++) {
		Enemy* e = new Enemy("../images/enemy.png", sf::Vector2f(i*15,i*10));
		Enemies.push_back(e);
		
	}
	
}

// talvez criar um booleano para checar se o jogo est� pausado?
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
