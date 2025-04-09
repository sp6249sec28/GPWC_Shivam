#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main(){
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Pong", Style::Fullscreen);
	
	int score = 0;
	int lives = 2;
	Bat bat(1920/2, 1080-20);
	Ball ball(1920/2, 0);
	
	// CREATE TEXT HUD
	Text hud;
	Font font;
	font.loadFromFile("./fonts/KOMIKAP_.ttf");
	
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);
	
	Clock clock;
	
	while (window.isOpen())
	{
		// HANDLE PLAYER INPUT
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed){
				//CLOSE OR QUIT THE GAME WHEN THE WINDOW CLOSES
				window.close();
			}
		}
		
		// IF THE PLAYER IS PRESSING 'ESCAPE' FOR QUITTING
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		
		// IF THE PLAYER IS PRESSING LEFT ARROW TO MOVE THE BAT
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}
		else{
			bat.stopLeft();
		}
		
		// IF THE PLAYER IS PRESSING RIGHT ARROW TO MOVE THE BAT
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}
		else{
			bat.stopRight();
		}
		
		// UPDATE THE DELTA TIME
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		
		std::stringstream ss;
		ss << "Score : " << score << " Lives : " << lives;
		hud.setString(ss.str());
		
		// BALL HITTING THE GROUND
		if (ball.getPosition().top > window.getSize().y){
			ball.reboundBottom();
			lives--;
			score--;
			
			if (lives < 1){
				score = 0;
				lives = 3;
			}
		}
		
		if (ball.getPosition().top < 0){
			ball.reboundBatorTop();
			score ++;
		}
		
		if (ball.getPosition().left < 0 || (ball.getPosition().left + ball.getPosition().width) > window.getSize()){
			ball.reboundSides();
		}
		
		if (ball.getPosition().intersects(bat.getPosition())){
			ball.reboundBatorTop();
		}
		
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
}
//Compile code : g++ pong.cpp bat.cpp -o pong -lsfml-window -lsfml-system -lsfml-graphics
