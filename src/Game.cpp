#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow* window)
{
	this->player = nullptr; // o jogador só é carregado quando o jogo inicia
	this->renderWindow = window;
	this->running = true;
	this->inMenu = true;
	this->enemies.reserve(5); // vetor começa vazio e reserva espaço para 500 ponteiros
	this->bullets.reserve(100);
	this->attackTimer = new sf::Clock;
	this->hud = new Hud;
	this->weapon = nullptr;
}

Game::~Game()
{
}

sf::RenderWindow* Game::getRenderWindow()
{
	return this->renderWindow;
}

bool Game::getEvents(sf::Event& event)
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

	Bullet* b = new Bullet(this->weapon->getBulletTexture(), this->player->getPos());
	b->setDirection(direction);
	this->bullets.push_back(b);

}

// todos o que vai ser desenhado na tela precisa acontecer aqui
void Game::updateFrame()
{

	if (this->weapon->checkAttackTimer(this->attackTimer)) {
		this->PlayerAttack(static_cast<sf::Vector2f>(this->mouse.getPosition(*(this->renderWindow))));
	}

	this->renderWindow->clear(sf::Color::Black);
	this->renderWindow->draw(this->player->getSprite());

	if (!bullets.empty()) {
		for (auto& bullet : this->bullets) {
			bullet->moveDirection();
			for (auto& enemy : this->enemies) {
				if (bullet->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
					enemy->setHealth(enemy->getHealth() - 0.001f);
				}
			}
			this->renderWindow->draw(bullet->getSprite());
		}
	}

	if (!enemies.empty()) {
		for (auto& enemy : this->enemies) {
			if (enemy->isDead()) {
				//enemies.erase(); deletar da memoria, fazer para bullets
				continue;
			}
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

	Player* p = new Player("../images/Player/move.png", sf::Vector2f(200.0f, 150.0f));
	this->player = p;


	for (int i = 0; i < 5; i++) {
		Enemy* e = new Enemy("../images/enemy.png", sf::Vector2f(i * 15, i * 10));
		enemies.push_back(e);
	}


	this->weapon = new Weapon(bullet);
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
