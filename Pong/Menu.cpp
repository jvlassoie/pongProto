#include "Menu.h"



Menu::Menu(sf::RenderWindow& window)
{
	this->cmpBoum = 25;
	this->cmpBoumIntervale = 0;
	this->cmpBoumBool = false;
	this->screenWidth = window.getSize().x;
	this->screenHeight = window.getSize().y;

	this->font = sf::Font();
	this->font.loadFromFile("C:/Users/val-l/Documents/Visual Studio 2017/Projects/Pong/assets/fonts/AvenirLTStd-Black.otf");

	this->title = sf::Text();
	this->instruction = sf::Text();

	this->title.setFont(this->font);
	this->instruction.setFont(this->font);


	this->title.setCharacterSize(50);
	this->instruction.setCharacterSize(this->cmpBoum);


	this->title.setStyle(sf::Text::Bold);
	this->instruction.setStyle(sf::Text::Bold);
	

	

	this->title.setPosition(this->screenWidth /2 - this->screenWidth / 16, this->screenHeight / 2 - this->screenHeight / 16);
	this->instruction.setPosition(this->screenWidth / 2 - this->screenWidth / 18, this->screenHeight / 2 + this->screenHeight / 16);
	
	this->title.setString("PONG");
	this->instruction.setString("Press start");
}


void Menu::update(std::string &screen)
{

	this->gestionClavier(screen);

	//boum
/*
	
	if (this->cmpBoumIntervale >= 5)
	{
		
		this->cmpBoumBool = true;

	}
	else if(this->cmpBoumIntervale <= 0)
	{
		
		this->cmpBoumBool = false;
		
	}

	if (this->cmpBoumBool == true)
	{
		this->cmpBoumIntervale--;
		this->cmpBoum--;
	}
	else if (this->cmpBoumBool == false)
	{
		this->cmpBoumIntervale++;
		this->cmpBoum++;
	}

	this->instruction.setCharacterSize(this->cmpBoum);
	*/


}

void Menu::draw(sf::RenderWindow& window)
{


	window.draw(this->title);
	window.draw(this->instruction);
	window.display();
	window.clear();

}


void Menu::gestionClavier(std::string &screen)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		screen = "game";
	}

}