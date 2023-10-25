#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow* window)
{
	this->player = nullptr; // o jogador só é carregado quando o jogo inicia
	this->renderWindow = window;
	this->running = true;
	this->inMenu = true;
	this->enemies.reserve(5); // vetor começa vazio e reserva espaço para 500 ponteiros
	this->attackTimer = new sf::Clock;
	this->hud = new Hud;
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

void Game::PlayerAttack(sf::Vector2f direction)
{
	this->player->attack(direction);
}

// todos o que vai ser desenhado na tela precisa acontecer aqui
void Game::updateFrame()
{
	
		if (this->player->checkAttackTimer(this->attackTimer)) {
			this->PlayerAttack(static_cast<sf::Vector2f>(this->mouse.getPosition(*(this->renderWindow))));
		}

		this->renderWindow->clear(sf::Color::Black);
		this->renderWindow->draw(this->player->getSprite());
		this->player->drawBullets(this->renderWindow);

		if (!enemies.empty()) {
			for (auto& enemy : this->enemies) {
				enemy->goToPlayer(this->player->getPos());
				if (enemy->getSprite().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
					enemy->attack(this->player);
				}

				this->renderWindow->draw(enemy->getSprite());
			}
		}

		this->hud->updateHud(this->renderWindow, *(this->player));

		if (player->isDead()) {
			this->quitGame();
		}

		this->renderWindow->display();
}


void Game::startGame()
{
	this->inMenu = false;
	sf::Texture* bullet = new sf::Texture;
	bullet->loadFromFile("../images/Bullet/Simple_Bullet.png");

	Player* p = new Player("../images/Player/move.png",bullet ,sf::Vector2f(200.0f, 150.0f));
	this->player = p;
	

	for (int i = 0; i < 5; i++) {
		Enemy* e = new Enemy("../images/enemy.png", sf::Vector2f(i*15,i*10));
		enemies.push_back(e);
	}

	this->attackTimer->restart();
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
