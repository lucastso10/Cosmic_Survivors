#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Game::Game()
{
	this->renderWindow = new sf::RenderWindow(sf::VideoMode(1360, 750), "Wipe Out!");
	this->renderWindow->setFramerateLimit(200);

	this->player = nullptr; // o jogador só é carregado quando o jogo inicia
	this->running = true;
	this->inMenu = true;
	this->attackTimer = new sf::Clock;
	this->hud = new Hud;
	this->weapon = nullptr;
	this->map = nullptr;

	this->shootSoundBuffer.loadFromFile("../sounds/normal_shot.wav");
	this->shootSound.setBuffer(this->shootSoundBuffer);
	this->shootSound.setVolume(60.f);

	this->critSoundBuffer.loadFromFile("../sounds/crit_sound.wav");
	this->critSound.setBuffer(this->critSoundBuffer);

	this->enemyDiesBuffer.loadFromFile("../sounds/inimigo_morre.wav");
	this->enemyDies.setBuffer(this->shootSoundBuffer);

	this->bossDiesBuffer.loadFromFile("../sounds/boss_morre.wav");
	this->enemyDies.setBuffer(this->bossDiesBuffer);

	this->music.openFromFile("../sounds/music_level.wav");
	this->music.setLoop(true);
	this->music.setVolume(40.f);

	this->enemySpawnRate = 3.f; //3.f	
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
	for (auto& bullet : this->bullets) {
		if (!(bullet->isDead()))
			continue;

		bullet->setHealth(1.f);
		bullet->setPos(this->player->getPos());
		bullet->setDirection(direction);
		break;
	}
	this->shootSound.play();
}

// todos o que vai ser desenhado na tela precisa acontecer aqui
void Game::updateFrame()
{

	this->renderWindow->clear(sf::Color::Black);
	// ================== Map ================================
	
	this->renderWindow->setView(this->renderWindow->getDefaultView());
	this->map->drawBackground(this->renderWindow);
	this->renderWindow->setView(this->view);

	this->map->drawMap(this->renderWindow);


	// ================== Player ================================
	
	// animação do player
	this->player->animate();
	
	// dependendo da posição do mouse a sprite inverte
	if (this->player->getSprite().getScale().x < 0 && this->mouse.getPosition(*(this->renderWindow)).x > this->renderWindow->getSize().x / 2)
		this->player->flip();
	else if (this->player->getSprite().getScale().x > 0 && this->mouse.getPosition(*(this->renderWindow)).x < this->renderWindow->getSize().x / 2)
		this->player->flip();

	// verifica se o player atira nesse frame se sim já aloca um nova instância no vetor
	if (this->weapon->checkAttackTimer(this->attackTimer)) 
		this->PlayerAttack(this->renderWindow->mapPixelToCoords(this->mouse.getPosition(*(this->renderWindow))));

	// desenha o player
	this->renderWindow->draw(this->player->getSprite());

	// move a camera junto com o player
	this->view.setCenter(this->player->getPos());
	this->renderWindow->setView(this->view);


	// ================== Bullets ================================

	// desenha os tiros na tela
	for (auto& bullet : this->bullets) {
		if (bullet->getDrawingText())
			this->renderWindow->draw(bullet->drawDamage());
		if (bullet->isDead())
			continue;
		bullet->moveDirection();
				
		// verifica se o tiro acertou algum inimigo
		for (auto& enemy : this->enemies) {
			if (enemy->isDead())
				continue;

			if (bullet->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
				bullet->enemiesHit++;
				int dano = (int)this->weapon->calculateDamage();
				enemy->setHealth(enemy->getHealth() - dano);
				this->renderWindow->draw(bullet->drawDamage(dano, this->weapon->getWasCrit()));
				if (this->weapon->getWasCrit())
					this->critSound.play();
				if (this->weapon->getPierce() <= bullet->enemiesHit){
					bullet->setHealth(0.f);
					bullet->enemiesHit = 0;
				}

				if (enemy->isDead()){
					this->enemyDies.play();
					this->player->incrementXp(10);
				}
			}

		}

		// repetição descarada e desnecessaria do código mas a gente precisa bota pra roda pra amanhã né
		if(!(this->boss->isDead())){ // se tiver um boss roda a mesma coisa dos outros
			if (bullet->getSprite().getGlobalBounds().intersects(boss->getSprite().getGlobalBounds())) {
				bullet->enemiesHit++;
				int dano = (int)this->weapon->calculateDamage();
				boss->setHealth(boss->getHealth() - dano);
				this->renderWindow->draw(bullet->drawDamage(dano, this->weapon->getWasCrit()));
				if (this->weapon->getWasCrit())
					this->critSound.play();
				if (this->weapon->getPierce() <= bullet->enemiesHit){
					bullet->setHealth(0.f);
					bullet->enemiesHit = 0;
				}

				if (boss->isDead()){
					this->bossDies.play();
					this->player->incrementXp(50);
				}
			}
		
		}
	      
		if (!(bullet->isOnScreen(this->renderWindow)))
			bullet->setHealth(0.f);

		this->renderWindow->draw(bullet->getSprite());
	}

	// ================== Enemy ================================
	
	// determina se precisa spawnar um novo inimigo
	if (this->enemySpawnClock.getElapsedTime().asSeconds() >= this->enemySpawnRate - (this->getGameTime() / 200))
	{
		for (auto& enemy : this->enemies) {
			if (!(enemy->isDead())) 
				continue;

			enemy->spawn(this->renderWindow);
			enemy->setHealth(enemy->getHealth() + (this->getGameTime() / 60));
			break;
		}
		this->enemySpawnClock.restart();
	}

	// determina se o boss vai spawnar
	if (this->boss->isDead() && (int)this->getGameTime() % 150 == 0 && (int)this->getGameTime() != 0){ // boss tem 50% de chance de spawnar a cada 3 mins
		int random = rand() % 2; 
		if (random == 0){
			boss->spawn(this->renderWindow);
			boss->setHealth(200 + (this->getGameTime() / 60) * 5);
		}
	}

	// desenha o boss em cima dos inimigos!!
	if (!(this->boss->isDead())){
		boss->goToPlayer(this->player->getPos(), this->renderWindow->mapCoordsToPixel(boss->getPos()), true);

		// verifica se o inimigo chegou perto do player
		if (boss->getSprite().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
			boss->attack(this->player);
		}

		this->renderWindow->draw(boss->getSprite());
	}
	
	// desenha os inimigos na tela
	for (auto& enemy : this->enemies) {
		if (enemy->isDead()) 
			continue;

		enemy->goToPlayer(this->player->getPos(), this->renderWindow->mapCoordsToPixel(enemy->getPos()), false);

		// verifica se o inimigo chegou perto do player
		if (enemy->getSprite().getGlobalBounds().intersects(this->player->getSprite().getGlobalBounds())) {
			enemy->attack(this->player);
		}

		this->renderWindow->draw(enemy->getSprite());
	}

	// ================== Hud ================================
	
	this->renderWindow->setView(this->renderWindow->getDefaultView());
	
	// atualiza o hud
	this->renderWindow->draw(this->hud->updateHpBar(this->player));
	this->renderWindow->draw(this->hud->updateLevel(this->player));
	this->renderWindow->draw(this->hud->updateXpBar(this->player));
	this->renderWindow->draw(this->hud->updateFPS());

	this->renderWindow->setView(this->view);

	// ================== Fim ================================

	if (player->isDead()) {
		this->quitGame();
	}

	this->renderWindow->display();
}


void Game::startGame()
{
	this->inMenu = false;

	Player* p = new Player(sf::Vector2f(2040.0f, 1125.0f));
	this->player = p;

	Map* m = new Map();
	this->map = m;

	sf::Texture* enemyTexture = new sf::Texture;
	enemyTexture->loadFromFile("../images/enemies/enemy.png"); // é melhor carregar a textura aqui fora pq eles todos usam a mesma textura
	for (int i = 0; i < 1000; i++) {
		Enemy* e = new Enemy(enemyTexture, false);
		enemies.push_back(e);
	}

	sf::Texture* bossTexture = new sf::Texture;
	bossTexture->loadFromFile("../images/enemies/boss.png");
	Enemy* e = new Enemy(bossTexture, true);
	this->boss = e;


	// o tipo de bala provavelmente vai trocar com o tipo de arma no futuro
	sf::Texture* bullet = new sf::Texture;
	bullet->loadFromFile("../images/Bullet/Simple_Bullet.png");
	this->weapon = new Weapon(bullet);
	
	for (int i = 0; i < 100; i++) {
		Bullet* b = new Bullet(this->weapon->getBulletTexture());
		this->bullets.push_back(b);
	};

	this->attackTimer->restart();

	this->view.reset(sf::FloatRect(0, 0, 1360, 750)); 
	this->renderWindow->setView(this->view);

	this->gameClock.restart();

	this->music.play();
}

// talvez criar um booleano para checar se o jogo está pausado?
void Game::pauseGame()
{
	this->gameClock.restart();
	// quando o jogo for continuar precisa fazer
	// this->recordedTime += gameClock.getElapsedTime();
	// this->gameClock.restart();
}

// precisa limpar a memoria antes
// não precisa não ótario o programa vai encerra
void Game::quitGame()
{
	this->running = false;
}

float Game::getGameTime()
{
	return (this->gameClock.getElapsedTime() + this->recordedTime).asSeconds();
}

bool Game::isRunning()
{
	return this->running;
}
