#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	this->player = nullptr; // o jogador só é carregado quando o jogo inicia
	this->renderWindow = window;
	this->running = true;
	this->inMenu = true;
	this->enemies.reserve(5); // vetor começa vazio e reserva espaço para 500 ponteiros
	
}

Game::~Game()
{
}

sf::RenderWindow* Game::getRenderWindow()
{
	return this->renderWindow;
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
		
		if (!enemies.empty()) {
			for (auto& enemy : this->enemies) {
				this->renderWindow->draw(enemy->getSprite());
				enemy->goToPlayer(this->player->getPos());
			}
			
		}
	}
	this->renderWindow->display();
}


void Game::startGame()
{
	this->inMenu = false;
	Player* p = new Player("../images/Player/move.png", sf::Vector2f(200.0f, 150.0f));
	this->player = p;
	

	for (int i = 0; i < 5; i++) {
		Enemy* e = new Enemy("../images/enemy.png", sf::Vector2f(i*15,i*10));
		enemies.push_back(e);
		
	}
	
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
