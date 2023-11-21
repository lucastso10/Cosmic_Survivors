#include "Menu.h"
using namespace std;

Menu::Menu(Game *game) {
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	image_option = new sf::Texture();
	bg = new sf::Sprite();
	option_bg = new sf::Sprite();
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
	image_option->loadFromFile("../images/menupausa.png");

	bg->setTexture(*image);
	option_bg->setTexture(*image_option);
	options_main_menu = { "Wipe Out", "Jogar", "Opções", "Fechar" };
	texts.resize(4);
	coords = {{200,-80},{610,435},{620,595},{620,660}};
	sizes = {400,100,60,60};
	for (size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setString(options_main_menu[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Black);
		if (i == 0) { texts[i].setFillColor(sf::Color::Yellow); }
		else { texts[i].setFillColor(sf::Color::Black); }
		texts[i].setPosition(coords[i]);
	}
}

void Menu::draw_all() {
	game->getRenderWindow()->clear(sf::Color::Black);
	game->getRenderWindow()->draw(*bg);
	for (auto t : texts) {
		game->getRenderWindow()->draw(t);
	}
	game->getRenderWindow()->display();
}

void Menu::startgame_button() {
	game->startGame();
}

void Menu::draw_optionmenu() {
	game->getRenderWindow()->clear(sf::Color::Black);
	game->getRenderWindow()->draw(*option_bg);
	game->getRenderWindow()->display();
}

void Menu::run_main_menu() {
	game->MenuType = 1;
	draw_all();
}

void Menu::run_option_menu() {
	game->MenuType = 2;
	draw_optionmenu();
}