#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow* window)
{
	this->player = nullptr; // o jogador s� � carregado quando o jogo inicia
	this->renderWindow = window;
	this->running = true;
	this->inMenu = true;
	this->enemies.reserve(5); // vetor come�a vazio e reserva espa�o para 500 ponteiros
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

Player* Game::getPlayer()
{
	return this->player;
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

	this->renderWindow->clear(sf::Color::Black);

	// desenha o player
	this->renderWindow->draw(this->player->getSprite());

	// verifica se o player atira nesse frame se sim j� aloca um nova inst�ncia no vetor
	if (this->weapon->checkAttackTimer(this->attackTimer)) {
		this->PlayerAttack(static_cast<sf::Vector2f>(this->mouse.getPosition(*(this->renderWindow))));
	}

	// desenha os tiros na tela
	if (!bullets.empty()) {
		for (auto& bullet : this->bullets) {
			bullet->moveDirection();
			// verifica se o tiro acertou algum inimigo
			for (auto& enemy : this->enemies) {
				if (bullet->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
					enemy->setHealth(enemy->getHealth() - 0.001f); // seria bom uma fun��o para diminuir a vida de uma entidade
				}
			}

			this->renderWindow->draw(bullet->getSprite());
		}
	}

	// desenha os inimigos na tela
	if (!enemies.empty()) {
		for (auto& enemy : this->enemies) {

			// deleta a instancia de inimigo da memoria
			if (enemy->isDead()) {
				//enemies.erase(); deletar da memoria, fazer para bullets
				continue;
			}

			enemy->goToPlayer(this->player->getPos());

			// verifica se o inimigo chegou perto do player
			if (enemy->getSprite().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
				enemy->attack(this->player);
			}
			this->renderWindow->draw(enemy->getSprite());
		}
	}

	// atualiza o hud
	this->hud->updateHud(this->renderWindow, *(this->player));

	if (player->isDead()) {
		this->quitGame();
	}

	this->renderWindow->display();
}


void Game::startGame()
{
	this->inMenu = false;

	Player* p = new Player("../images/Player/move.png", sf::Vector2f(200.0f, 150.0f));
	this->player = p;


	for (int i = 0; i < 5; i++) {
		Enemy* e = new Enemy("../images/enemy.png", sf::Vector2f(i * 15, i * 10));
		enemies.push_back(e);
	}

	// o tipo de bala provavelmente vai trocar com o tipo de arma no futuro
	sf::Texture* bullet = new sf::Texture;
	bullet->loadFromFile("../images/Bullet/Simple_Bullet.png");
	this->weapon = new Weapon(bullet);

	this->attackTimer->restart();
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
