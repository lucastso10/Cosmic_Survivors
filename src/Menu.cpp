#include "Menu.h"

Menu::Menu(Game *game) {
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	this->game = game;
	set_values();
}

Menu::~Menu() {
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void Menu::set_values() {
	pos = 0;
	pressed = theselect = false;

	font->loadFromFile("../fonte/kenneypixel.ttf");
	image->loadFromFile("../images/telaprimeiradef.jpg");
	
	bg->setTexture(*image);

	options = { "Wipe Out", "Jogar", "Fechar" };
}

void Menu::draw_all() {
	game->getRenderWindow()->clear(sf::Color::Black);
	game->getRenderWindow()->draw(*bg);
	game->getRenderWindow()->display();
}

void Menu::startgame_button() {
	game->startGame();
}

void Menu::run_menu() {
	draw_all();
}