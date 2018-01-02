#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include <string>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

std::string screen  = "menu";
sf::RenderWindow window(sf::VideoMode(1024, 600), "Pong");
bool updateFps = true;


/*
debugLine

sf::RectangleShape debugLineX(sf::Vector2f(window.getSize().x , 4));
sf::RectangleShape debugLineY(sf::Vector2f(4, window.getSize().y));

*/



Game myGame(window);
Menu myMenu(window);

int main()
{

	/*
	debug Position
	

	debugLineX.setPosition(0, window.getSize().y / 2);
	debugLineY.setPosition(window.getSize().x / 2, 0);
	
	*/

	sf::Clock time;
	float fpsCount = 0,
		switchFps = 100,
		fpsSpeed = 500;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*
		debug Draw
		
		window.draw(debugLineX);
		window.draw(debugLineY);
		
		*/

		
		fpsCount += (updateFps)? fpsSpeed * time.restart().asSeconds() : 0;
		
		if (fpsCount >= switchFps) {

		
			if (screen == "game")
			{ 
			
				myGame.update();
				myGame.draw(window);
	
			}
			else if (screen == "menu")
			{

				myMenu.update(screen);
				myMenu.draw(window);

			}
	
		}
	}

	
	
	return 0;
}