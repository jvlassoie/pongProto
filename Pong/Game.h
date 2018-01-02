#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;


class Game
{
public:
	
	Game(sf::RenderWindow& window);

	
	
	void update();
	void draw(sf::RenderWindow& window);
	void gestionClavier();
	bool checkCollide(float r1X, float r1Y, float r1Width, float r1Height, float r2X, float r2Y, float r2Width, float r2Height);
	sf::Font font;
	
	sf::Text score1;
	sf::Text score2;

	int scorePlayer1;
	int scorePlayer2;

	bool startBall;

	sf::SoundBuffer soundBall;
	sf::Sound sound;

	//si haut faux sinon bas vrai
	bool lastBord = false;

	void contactBall(sf::RectangleShape racket);

private:
	float sizeBall = 8;
	float widthR = 10;
	float heightR = 100;
	
	int screenWidth;
	int screenHeight;


	int speedRacket = 1;
	float speedBallY = 0.5;
	float speedBallX = 0.5;


	sf::CircleShape ball;
	sf::RectangleShape racket1;
	sf::RectangleShape racket2;
	sf::RectangleShape line;

	
};