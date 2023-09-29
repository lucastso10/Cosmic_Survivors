#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	// o jogador só é carregado quando o jogo inicia
	this->player = nullptr;
	this->renderWindow = window;
	this->running = true;
	this->inMenu = true;


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
	}

	this->renderWindow->display();
}


void Game::startGame()
{
	this->inMenu = false;
	sf::Texture texture;
	texture.loadFromFile("../images/Peter_Griffin.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	Player* p = new Player(sprite, sf::Vector2f(200.0f, 150.0f));
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
