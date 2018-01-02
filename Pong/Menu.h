#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;


class Menu
{
public:
	Menu(sf::RenderWindow& window);
	void update(std::string &screen);
	void draw(sf::RenderWindow& window);
	int screenWidth;
	int screenHeight;
	int cmpBoum;
	int cmpBoumIntervale;
	int cmpBoumBool;
	void gestionClavier(std::string &screen);

private:

	sf::Text title;
	sf::Text instruction;
	sf::Font font;

};

