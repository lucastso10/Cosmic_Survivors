#include "Menu.h"
using namespace std;

Menu::Menu(Game *game) {
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
	options = { "Wipe Out", "Jogar", "Opções", "Fechar" };
	texts.resize(4);
	coords = {{200,-80},{610,435},{620,595},{620,660}};
	sizes = {400,100,60,60};
	for (size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Black);
		if (i == 0) { texts[i].setColor(sf::Color::Yellow); }
		else { texts[i].setColor(sf::Color::Black); }
		texts[i].setPosition(coords[i]);
	}

	music.openFromFile("../sounds/Title_screen.wav");
	music.setLoop(true);
	music.play();

	buffer.loadFromFile("../sounds/button_click.wav");
	buttonClick.setBuffer(buffer);
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

void Menu::playButtonClick()
{
	buttonClick.play();
}

void Menu::stopMusic()
{
	music.stop();
}

void Menu::run_menu() {
	draw_all();
}
