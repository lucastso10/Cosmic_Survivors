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
	this->map = nullptr;
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
	// ================== Map ================================
	this->map->drawMap(this->renderWindow);

	// ================== Player ================================

	// animação do player
	this->player->animate();

	// dependendo da posição do mouse a sprite inverte
	if (this->player->getSprite().getScale().x > 0 && this->mouse.getPosition(*(this->renderWindow)).x < this->player->getPos().x)
		this->player->flip();
	else if (this->player->getSprite().getScale().x < 0 && this->mouse.getPosition(*(this->renderWindow)).x > this->player->getPos().x)
		this->player->flip();

	// desenha o player
	this->renderWindow->draw(this->player->getSprite());

	// verifica se o player atira nesse frame se sim já aloca um nova instância no vetor
	if (this->weapon->checkAttackTimer(this->attackTimer)) 
		this->PlayerAttack(static_cast<sf::Vector2f>(this->mouse.getPosition(*(this->renderWindow))));



	// ================== Bullets ================================

	// desenha os tiros na tela
	if (!bullets.empty()) {
		for (auto& bullet : this->bullets) {
			bullet->moveDirection();
				
			// verifica se o tiro acertou algum inimigo
			for (auto& enemy : this->enemies) {
				if (bullet->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
					enemy->setHealth(enemy->getHealth() - 0.001f); // seria bom uma função para diminuir a vida de uma entidade
				}
			}

			this->renderWindow->draw(bullet->getSprite());
		}
	}

	// ================== Enemy ================================

	// desenha os inimigos na tela
	if (!enemies.empty()) {
		for (auto& enemy : this->enemies) {

			// deleta a instancia de inimigo da memoria
			if (enemy->isDead()) {
				//enemies.erase(); deletar da memoria, fazer para bullets
				continue;
			}

			

			enemy->goToPlayer(this->player->getPos(), enemies);

			// verifica se o inimigo chegou perto do player
			if (enemy->getSprite().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
				
				enemy->attack(this->player);
			}

			
			this->renderWindow->draw(enemy->getSprite());
		}
	}

	// ================== Hud ================================

	// atualiza o hud
	this->hud->updateHud(this->renderWindow, *(this->player));

	// ================== Fim ================================

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

	Map* m = new Map("../images/tileset.png");
	this->map = m;


	for (int i = 0; i < 3; i++) {
		Enemy* e = new Enemy("../images/enemy.png", sf::Vector2f(i * 300, i * 100));
		enemies.push_back(e);
	}

	// o tipo de bala provavelmente vai trocar com o tipo de arma no futuro
	sf::Texture* bullet = new sf::Texture;
	bullet->loadFromFile("../images/Bullet/Simple_Bullet.png");
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
