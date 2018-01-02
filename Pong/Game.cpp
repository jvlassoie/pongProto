#include "Game.h"


Game::Game(sf::RenderWindow& window)
{


	this->soundBall.loadFromFile("C:/Users/val-l/Documents/Visual Studio 2017/Projects/Pong/assets/sounds/ball.wav");
	

	this->screenWidth = window.getSize().x;
	this->screenHeight = window.getSize().y;
	
	this->ball = sf::CircleShape(this->sizeBall);
	
	this->racket1 = sf::RectangleShape(sf::Vector2f(this->widthR, this->heightR));
	this->racket2 = sf::RectangleShape(sf::Vector2f(this->widthR, this->heightR));
	
	this->line = sf::RectangleShape(sf::Vector2f(5, this->screenHeight));

	this->ball.setFillColor(sf::Color::Cyan);
	this->ball.setPosition(this->screenWidth/2,this->screenHeight/2);
	this->ball.setOrigin(sizeBall/2, sizeBall/2);
	
	this->racket1.setPosition(0 + this->widthR, this->screenHeight / 2 - this->heightR / 2);
	this->racket2.setPosition(this->screenWidth - this->widthR*2, this->screenHeight / 2 - this->heightR/2);

	this->line.setPosition(this->screenWidth / 2 + 5, 0);

	
	this->font = sf::Font();
	this->font.loadFromFile("C:/Users/val-l/Documents/Visual Studio 2017/Projects/Pong/assets/fonts/AvenirLTStd-Black.otf");

	this->score1 = sf::Text();
	this->score2 =  sf::Text();

	score1.setFont(this->font);
	score2.setFont(this->font);


	this->score1.setCharacterSize(50);
	this->score2.setCharacterSize(50);


	this->score1.setStyle(sf::Text::Bold);
	this->score2.setStyle(sf::Text::Bold);

	this->scorePlayer1 = 0;
	this->scorePlayer2 = 0;

	this->startBall = false;

	this->score1.setPosition(this->screenWidth / 4, 0);
	this->score2.setPosition(this->screenWidth / 4 + this->screenWidth / 2, 0);

}


void Game::update() 
{

	//boolean collidde detection
	bool collideRacket1;
	bool collideRacket2;
	


	//clavier
	this->gestionClavier();

	//bord limite
	
	//palyer 1
	if (this->racket1.getPosition().y <= 0)
	{
	
		this->racket1.setPosition(this->racket1.getPosition().x,0);
	
	}
	
	if (this->racket1.getPosition().y >= this->screenHeight - this->heightR)
	{
	
		this->racket1.setPosition(this->racket1.getPosition().x, this->screenHeight - this->heightR);
	
	}


	//player2
	if (this->racket2.getPosition().y <= 0)
	{
	
		this->racket2.setPosition(this->racket2.getPosition().x, 0);
	
	}

	if (this->racket2.getPosition().y >= this->screenHeight - this->heightR)
	{

		this->racket2.setPosition(this->racket2.getPosition().x, this->screenHeight - this->heightR);

	}

	//balle bord
	if (this->ball.getPosition().y <= 0 || this->ball.getPosition().y >= this->screenHeight - this->sizeBall)
	{
		if (this->ball.getPosition().y <= 0)
		{
			
			this->lastBord = false;
			
		}
		else
		{

			this->lastBord = true;

		}
		
		this->speedBallY = -this->speedBallY;
		

	}

	//score
	if (this->ball.getPosition().x <= 0)
	{

		this->scorePlayer2++;
		this->ball.setPosition(this->screenWidth / 2, this->screenHeight / 2);
		this->startBall = false;

	}

	if (this->ball.getPosition().x >= this->screenWidth)
	{

		this->scorePlayer1++;
		this->ball.setPosition(this->screenWidth / 2, this->screenHeight / 2);
		this->startBall = false;

	}


	//deplacement ball
	if (this->startBall)
	{

		this->ball.move(this->speedBallX, this->speedBallY);

	}

	
		

	//check collide

	//entre la balle et le premier player 
	collideRacket1 = this->checkCollide(float (this->racket1.getPosition().x), float (this->racket1.getPosition().y), float (this->widthR), float (this->heightR), float (this->ball.getPosition().x), float (this->ball.getPosition().y), float (this->sizeBall), float (this->sizeBall));

	//entre la balle et le deuxieme player 
	collideRacket2 = this->checkCollide(float (this->racket2.getPosition().x), float (this->racket2.getPosition().y), float (this->widthR), float (this->heightR), float (this->ball.getPosition().x), float (this->ball.getPosition().y), float (this->sizeBall), float (this->sizeBall));

	//frappe dans la balle 
	if (collideRacket1 || collideRacket2)
	{

	
		//différencier le haut du bas et qui touche !
		
		if (collideRacket1) {
			
			this->contactBall(this->racket1);

		}

		if (collideRacket2) {
		
			this->contactBall(this->racket2);

		}

		//inversion axe X a chaque contact
		this->speedBallX = -this->speedBallX;
		
		//son de la ball

		this->sound.setBuffer(this->soundBall);
		
		this->sound.play();

	}

}



void Game::draw(sf::RenderWindow& window)
{
	window.draw(this->line);
	window.draw(this->ball);
	window.draw(this->racket1);
	window.draw(this->racket2);

	this->score1.setString(std::to_string(this->scorePlayer1));
	this->score2.setString(std::to_string(this->scorePlayer2));

	window.draw(this->score1);
	window.draw(this->score2);
	
	window.display();
	window.clear();
}




void Game::gestionClavier() 
{

	//premier player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		
		this->racket1.move(0,-this->speedRacket);
	
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	
		this->racket1.move(0, this->speedRacket);
		
	}
	
	
	
	//deuxieme player

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		this->racket2.move(0, -this->speedRacket);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		this->racket2.move(0, this->speedRacket);

	}


	//ball

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

		
		this->startBall = true;

	}
}


//collide Rect
bool Game::checkCollide(float r1X, float r1Y, float r1Width, float r1Height, float r2X, float r2Y, float r2Width, float r2Height)
{

	if (r1X <= r2X + r2Width && r1X + r1Width >= r2X && r1Y <= r2Y + r2Height && r1Y + r1Height >= r2Y)
	{
		
		return true;
	}
	else
	{
		return false;
	}

}


//retour ball contact

void Game::contactBall(sf::RectangleShape racket)
{

	if (racket.getPosition().y + this->heightR / 2 > this->ball.getPosition().y )
	{
		//haut
		//si vient du haut on inverse sinon non
		this->speedBallY = (this->lastBord)? -this->speedBallY : this->speedBallY;
		
	}
	else
	{
		//bas
		//si vient du bas on inverse sinon non
		this->speedBallY = (this->lastBord) ? this->speedBallY : -this->speedBallY;
	
	}

}