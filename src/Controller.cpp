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

	}
	else {
		this->eventHandlerGame();
	}
}
//530 480
//828 544
void Controller::eventHandlerMenu() {
	while (this->game->getEvents(this->event))
	{
		switch (this->event.type) {
			case sf::Event::MouseButtonReleased: 
				if (event.mouseButton.button == sf::Mouse::Left) {
					std::cout << "BANANA";
					if (event.mouseButton.x >= 530 && event.mouseButton.x <= 828 && event.mouseButton.y >= 480 && event.mouseButton.y <= 544) {
						menu->startgame_button();
					}
				}
				break;
		
			case sf::Event::Closed:
				this->game->quitGame();
				break;
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
			// eventos do tipo tecla foi apertada
		case sf::Event::KeyPressed:
			switch (this->event.key.code)
			{
				// tecla direita
			case sf::Keyboard::D:
				this->flags[sf::Keyboard::D] = true;
				break;
			case sf::Keyboard::A:
				this->flags[sf::Keyboard::A] = true;
				break;
			case sf::Keyboard::W:
				this->flags[sf::Keyboard::W] = true;
				break;
			case sf::Keyboard::S:
				this->flags[sf::Keyboard::S] = true;
				break;
			default:
				break;
			}
			break;
		case sf::Event::KeyReleased:
			switch (this->event.key.code)
			{
				// tecla direita
			case sf::Keyboard::D:
				this->flags[sf::Keyboard::D] = false;
				break;
			case sf::Keyboard::A:
				this->flags[sf::Keyboard::A] = false;
				break;
			case sf::Keyboard::W:
				this->flags[sf::Keyboard::W] = false;
				break;
			case sf::Keyboard::S:
				this->flags[sf::Keyboard::S] = false;
				break;
			default:
				break;
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

	// tratando as flags, talvez tenha um melho jeito de fazer isso
	if (this->flags[sf::Keyboard::D])
		this->game->movePlayer(sf::Vector2f(0.1f, 0.0f));

	if (this->flags[sf::Keyboard::A])
		this->game->movePlayer(sf::Vector2f(-0.1f, 0.0f));

	if (this->flags[sf::Keyboard::W])
		this->game->movePlayer(sf::Vector2f(0.0f, -0.1f));

	if (this->flags[sf::Keyboard::S])
		this->game->movePlayer(sf::Vector2f(0.0f, 0.1f));
}

void Controller::interpretKey()
{
}
