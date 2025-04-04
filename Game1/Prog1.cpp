//#include "stdafx.h"  //This line is only used in Visual Studio
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

//adding branches to the tree
const int  NUM_BRANCHES=6;
Sprite branches[NUM_BRANCHES];

//Where is the Player/Branch ?
enum class side { LEFT, RIGHT, NONE };
side branchPositions[NUM_BRANCHES];

//Function to update the positions of the branches
void updateBranches(int seed);

int main(){
	//Create video mode object
	VideoMode vm(1920, 1080);
	
	//Create & open a window
	RenderWindow window(vm, "Timber", Style::Fullscreen);
	
	//Create an object that will hold a graphics on GPU
	Texture textureBackground;
	
	//load graphics on the texture
	textureBackground.loadFromFile("graphics/background.png");
	
	//Create a sprite
	Sprite spriteBackground;
	
	//Link texture to sprite
	spriteBackground.setTexture(textureBackground);
	
	//set the spritebackground position to cover the screen
	spriteBackground.setPosition(0, 0);
	
	//Load tree texture and create a sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);
	
	//Preparing for bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 2000);
	
	//Is the bee currently moving
	bool beeActive = false;
	//How fast the bee can fly
	float beeSpeed = 0.0f;
	
	//Load cloud texture and create three cloud sprites
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	
	//3 new sprites will be added 
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	
	//Set cloud positions
	spriteCloud1.setPosition(-500, 0);
	spriteCloud2.setPosition(-500, 150);
	spriteCloud3.setPosition(-500, 300);
	
	//Are the clouds curently moving
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	
	//How fast the cloud should be moving
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	
	//Variable to control the time
	Clock clock;
	
	//Adding the time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920/2) - timeBarStartWidth/2, 980);
	
	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
	
	//Track whether the game is running or not
	bool paused = true;
	
	//Variable for holding score
	int score = 0;
	
	sf::Text messageText;
	sf::Text scoreText;
	
	//Choose fonts
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	
	//Set the fonts to our message
	messageText.setFont(font);
	scoreText.setFont(font);
	
	//Assign the output message
	messageText.setString("Press ENTER to start!");
	scoreText.setString("Score = 0");
	
	//Setting character size of the font
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	
	//Choose a color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width/2.0f , textRect.top + textRect.height/2.0f);
	messageText.setPosition(1920/2.0f, 1080/2.0f);
	scoreText.setPosition(20, 20);
	
	//Preparing for branch
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");
	
	//set texture for each branch in the sprite
	for (int i=0; i<NUM_BRANCHES; i++){
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);
		
		//set sprite origin
		//we can rotate the branches without changing the position
		branches[i].setOrigin(220, 20);
	}
	
	/*updateBranches(1);
	updateBranches(2);
	updateBranches(3);
	updateBranches(4);
	updateBranches(5);
	*/
	
	//Prepare the Player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);
	
	// The player starts on the left
	side playerSide = side::LEFT;
	
	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(600, 2000);
	
	//Preparing for axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(700, 830);
	
	// align the axe with the tree
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;
	
	//Preparing for log
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 720);
	
	//Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;
	
	//Control the player input
	bool acceptInput = false;
	
	//Prepare the sound
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);
	
	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);
	
	//Out of time
	SoundBuffer ootBuffer;
	ootBuffer.loadFromFile("sound/out_of_time.wav");
	Sound outOfTime;
	outOfTime.setBuffer(ootBuffer);
	
		
	while (window.isOpen()){
	
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::KeyReleased && !paused)
			{
				//Listen for key presses again
				acceptInput = true;
				
				//hide the axe
				spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
			}
		}
		
		//*****************************************//
		//          Handle player input            //
		//*****************************************//
		 
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		
		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
			// Reset the time and the score
			score = 0;
			timeRemaining = 6;
			
			//Make all the branches disappear
			for (int i=1; i<NUM_BRANCHES; i++){
				branchPositions[i] = side::NONE;
			}
			
			//Make sure the gravestone is hidden
			spriteRIP.setPosition(675, 2000);
			
			//Move the player into position
			spritePlayer.setPosition(580, 720);
			
			acceptInput = true;
			
		}
		
		//Chopping
		if(acceptInput){
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				//Make sure the player is on the right
				playerSide = side::RIGHT;
				
				score++; //1
				
				//Add the amount of time remaining
				timeRemaining += (2/score) + 0.15;
				
				spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
				
				spritePlayer.setPosition(1200, 720);
				
				//Update the branches
				updateBranches(score);
				
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;
				
				acceptInput = false;
				
				chop.play();
			}
			
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				//Make sure the player is on the left
				playerSide = side::LEFT;
				
				score++; //1
				
				//Add the amount of time remaining
				timeRemaining += (2/score) + 0.15;
				
				spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
				
				spritePlayer.setPosition(580, 720);
				
				//Update the branches
				updateBranches(score);
				
				spriteLog.setPosition(810, 720);
				logSpeedX = 5000;
				logActive = true;
				
				acceptInput = false;
				
				chop.play();
			}
		}
		//Updating the scene
		if(!paused)
		{
			//Measure the time
			Time dt = clock.restart();
			
			//Subtract the amount of time remaining
			timeRemaining -= dt.asSeconds();
			//size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond *
				timeRemaining, timeBarHeight));
			
			if (timeRemaining <= 0.0f) {
				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("Out of time!!");
	
				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
				
				// Play the out of time sound
				outOfTime.play();
	
			}
				
			if (!beeActive){
				srand((int)time(0));
				beeSpeed = (rand()%200) + 200;  //Bee speed is between 200 and 400
			
				//deciding the height of the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000,height);
				beeActive = true;
			}
			else{
				spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
			
				//// Has the bee reached the right hand edge of the screen?
				if(spriteBee.getPosition().x < -100){
					beeActive = false;
				}
			}
		
			//Cloud movement
			
			//For cloud 1
			if(!cloud1Active){
				srand((int) time(0) * 10);
				cloud1Speed = (rand() % 200);
				//height of cloud
				srand((int)time(0)*10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			}
			else{
				spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
			
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920){
					cloud1Active = false;
				}
			}
			//For cloud 2
			if(!cloud2Active){
				srand((int)time(0)*20);
				cloud2Speed = (rand() % 200);
				//height of cloud
				srand((int)time(0)*20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			}
			else{
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
				
				if (spriteCloud2.getPosition().x > 1920){
					cloud2Active = false;
				}
			}
			//For cloud 3
			if(!cloud3Active){
				srand((int)time(0)*30);
				cloud3Speed = (rand() % 200);
				//height of cloud
				srand((int)time(0)*30);
				float height = (rand() % 450) - 150 ;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;
			}
			else{
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
			
				if (spriteCloud3.getPosition().x > 1920){
					cloud3Active = false;
				}
			}
	
			//Update the score
			std::stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());
			
			// update the branch sprites
			for (int i=0; i<NUM_BRANCHES; i++)
			{
				float height = i * 150;
				
				if (branchPositions[i] == side::LEFT){
					//Move the sprite to the left side
					branches[i].setPosition(600, height);
					//set the sprite rotation to normal
					branches[i].setRotation(180);
				}	
				else if (branchPositions[i] == side::RIGHT){
					//Move the sprite to the right side
					branches[i].setPosition(1330, height);
					//set the sprite rotation to normal
					branches[i].setRotation(0);
				}
				else{
					//Hide the branch
					branches[i].setPosition(3000, height);
				}
			}
			
			//Handle a flying log
			if(logActive){
				
				spriteLog.setPosition(
					spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
					spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));
					
				//Has the insect reached the right side of the screen
				if ( spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000){
					logActive = false;
					spriteLog.setPosition(810, 720);
				}
			}
			
			//Has the player been squished by the branch ?
			if (branchPositions[5] == playerSide)
			{
				//death
				paused = true;
				acceptInput = false;
				
				//Draw the gravestone
				spriteRIP.setPosition(525, 760);
				
				//hide the player
				spritePlayer.setPosition(2000, 660);
				
				//Change the text of the message
				messageText.setString("GAME OVER !!!");
				messageText.setFillColor(Color::Red);
				
				//Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();
				
				messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				
				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
				
				//Play the death sound
				death.play();
			}
		}
		//End if(!paused)
		
		//***************************************************************//
		//                         Drawing Board                                         //
		//***************************************************************//
		
		window.clear(); //Clear everything from the last frame
		
		window.draw(spriteBackground); //Draw our game scene here
		
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		
		for (int i = 0; i < NUM_BRANCHES; i++){
			window.draw(branches[i]);
		}
		window.draw(spriteTree);
		window.draw(spritePlayer);
		window.draw(spriteAxe);
		window.draw(spriteLog);
		window.draw(spriteRIP);
		window.draw(spriteBee);
		window.draw(scoreText);
		window.draw(timeBar);
		
		if(paused){
			window.draw(messageText);
		}
		//Display everything
		window.display();
	}
	
	return 0;
}

//Function to update branches
void updateBranches(int seed){
	for (int j=NUM_BRANCHES-1; j>0; j--){
		branchPositions[j] = branchPositions[j - 1];
	}
	
	//Spawn a new branch at position 0
	//LEFT,RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);
	
	switch(r){
	case 0:
		branchPositions[0] = side::LEFT;
		break;
		
	case 1:
		branchPositions[0] = side::RIGHT;
		break;
		
	default:
		branchPositions[0] = side::NONE;
		break;
	}
}

//Compile code : g++ Prog1.cpp -o timber -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
