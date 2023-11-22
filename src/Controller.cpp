#include "Controller.h"

Controller::Controller(Game* game, Menu* menu)
{
	this->game = game;
	this->menu = menu;
	this->flags = {
		{sf::Keyboard::D  , false},
		{sf::Keyboard::A  , false},
		{sf::Keyboard::W  , false},
		{sf::Keyboard::S  , false},
	};
}

Controller::~Controller()
{
}

void Controller::eventHandler()
{
	if (this->game->isInMenu()) {
		if (this->game->MenuType == 1)
			this->eventHandlerMainMenu();
		else if (this->game->MenuType == 2)
			this->eventHandlerOptionMenu();
	}
	else {
		this->eventHandlerGame();
	}
}

void Controller::eventHandlerMainMenu() {
	while (this->game->getEvents(this->event))
	{
		switch (this->event.type) {
			case sf::Event::MouseButtonReleased: 
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (event.mouseButton.x >= 530 && event.mouseButton.x <= 828 && event.mouseButton.y >= 480 && event.mouseButton.y <= 544) {
						menu->playButtonClick();
						menu->stopMusic();
						menu->startgame_button();
					}
					if (event.mouseButton.x >= 602 && event.mouseButton.x <= 757 && event.mouseButton.y >= 689 && event.mouseButton.y <= 721) {
						this->game->quitGame();
					}
					if (event.mouseButton.x >= 558 && event.mouseButton.x <= 802 && event.mouseButton.y >= 614 && event.mouseButton.y <= 662) {
						menu->run_option_menu();
					}
				}
				break;
		
			case sf::Event::Closed:
				this->game->quitGame();
				break;
		}
	}

}

void Controller::eventHandlerOptionMenu() {
	while (this->game->getEvents(this->event)) {
		switch (this->event.type) {
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (event.mouseButton.x >= 40 && event.mouseButton.x <= 290 && event.mouseButton.y >= 40 && event.mouseButton.y <= 100) {
						menu->run_main_menu();
					}
					if (event.mouseButton.x >= 1070 && event.mouseButton.x <= 1320 && event.mouseButton.y >= 40 && event.mouseButton.y <= 100) {
						this->game->quitGame();
					}
				}
		}
	}

}
void Controller::eventHandlerGame() 
{
	/*
	* Da poll em todos os eventos da janela,
	* ou seja, fechar janela, apertar tecla,
	* mexer mouse, clickar mouse etc.
	* Tipos de eventos:
	* https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1Event.php#af41fa9ed45c02449030699f671331d4a
	*/
	while (this->game->getEvents(this->event))
	{
		switch (this->event.type)
		{
			/*
			esses switchs de KeyPressed e KeyReleased com certeza da pra deixa
			de um jeito mais esperto, pra toda a vez que a gente quiser adiciona uma
			tecla nova não ter que adiciona aqui no map e no ifs lá me baixo
			*/
			// evento do tipo tecla foi apertada
			case sf::Event::KeyPressed:
				// checa o mapa flags e se a tecla estiver nele marca a flag como true
				for (auto& key : this->flags){
					if (this->event.key.code == key.first){
						this->flags[this->event.key.code] = true;
						break;
					}
				}
				break;

			// evento soltar tecla
			case sf::Event::KeyReleased:
				// faz a mesma coisa que o de cima só que marca false
				for (auto& key : this->flags){
					if (this->event.key.code == key.first){
						this->flags[this->event.key.code] = false;
						break;
					}
				}
			break;

			// evento para fechar o jogo
			case sf::Event::Closed:
				this->game->quitGame();
				break;
			default:
				break;
		}
	}

	bool moved = false;
	Player* player = this->game->getPlayer();
	// tratando as flags, talvez tenha um melho jeito de fazer isso
	if (this->flags[sf::Keyboard::D] && player->getPos().x < 4070) { // tamanho do mapa hard coded foda-se B)
		player->move(sf::Vector2f(player->getSpeed(), 0.0f)); // precisa de alteração para a velocidade do player mudar
		player->setWalking(true);
		moved = true;
	}

	if (this->flags[sf::Keyboard::A] && player->getPos().x > 10) {
		player->move(sf::Vector2f(player->getSpeed() * -1, 0.0f));
		player->setWalking(true);
		moved = true;
	}

	if (this->flags[sf::Keyboard::W] && player->getPos().y > 10) {
		player->move(sf::Vector2f(0.0f, player->getSpeed() * -1));
		player->setWalking(true);
		moved = true;
	}

	if (this->flags[sf::Keyboard::S] && player->getPos().y < 2240) {
		player->move(sf::Vector2f(0.0f, player->getSpeed()));
		player->setWalking(true);
		moved = true;
	}

	if (moved == false)
		player->setWalking(false);
}

void Controller::interpretKey()
{
}
