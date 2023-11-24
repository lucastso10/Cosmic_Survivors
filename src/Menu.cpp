#include "Menu.h"
using namespace std;

Menu::Menu(Game *game) {
	font = new sf::Font();
	image = new sf::Texture();
	image_option = new sf::Texture();
	bg = new sf::Sprite();
	option_bg = new sf::Sprite();
	this->game = game;
	set_values();
}

Menu::~Menu() {
	delete font;
	delete image;
	delete bg;
}

void Menu::set_values() {
	pos = 0;
	pressed = theselect = false;

	font->loadFromFile("../fonte/kenneypixel.ttf");
	image->loadFromFile("../images/telaprimeiradef.jpg");
	image_option->loadFromFile("../images/menupausa.jpg");

	bg->setTexture(*image);
	option_bg->setTexture(*image_option);

	options_main_menu = { "Wipe Out", "Jogar", "Opcoes", "Fechar" };
	main_menu_texts.resize(4);
	main_menu_coords = {{200,-80},{610,435},{620,595},{620,660}};
	main_menu_sizes = {400,100,60,60};
	for (size_t i{}; i < main_menu_texts.size(); ++i) {
		main_menu_texts[i].setFont(*font);
		main_menu_texts[i].setString(options_main_menu[i]);
		main_menu_texts[i].setCharacterSize(main_menu_sizes[i]);
		main_menu_texts[i].setOutlineColor(sf::Color::Black);
		if (i == 0) { main_menu_texts[i].setFillColor(sf::Color::Yellow); }
		else { main_menu_texts[i].setFillColor(sf::Color::Black); }
		main_menu_texts[i].setPosition(main_menu_coords[i]);
	}

	options_option_menu = {"Voltar", "Fechar", "Mostrar dano", "Mostrar FPS", "Sons", "Musica"};
	option_menu_texts.resize(6);
	option_menu_coords = { {80,8}, {1120,8}, {570,155}, {570,275}, {640,395}, {625,515} };
	option_menu_sizes = {80,80,55,55,55,55};
	for (size_t i{}; i < option_menu_texts.size(); ++i) {
		option_menu_texts[i].setFont(*font);
		option_menu_texts[i].setString(options_option_menu[i]);
		option_menu_texts[i].setCharacterSize(option_menu_sizes[i]);
		option_menu_texts[i].setOutlineColor(sf::Color::Black);
		option_menu_texts[i].setFillColor(sf::Color::Black);
		option_menu_texts[i].setPosition(option_menu_coords[i]);
	}
	music.openFromFile("../sounds/Title_screen.wav");
	music.setLoop(true);
	music.setVolume(50.f);
	music.play();

	buffer.loadFromFile("../sounds/button_click.wav");
	buttonClick.setBuffer(buffer);
}

void Menu::draw_all() {
	game->getRenderWindow()->clear(sf::Color::Black);
	game->getRenderWindow()->draw(*bg);
	for (auto t : main_menu_texts) {
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
	for (auto t : option_menu_texts) {
		game->getRenderWindow()->draw(t);
	}
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

void Menu::playButtonClick()
{
	buttonClick.play();
}

void Menu::stopMusic()
{
	music.stop();
}
