//main driver file for ND Tailgate

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "LTexture.h"
#include "StaticScreen.h"
#include "OpeningScreen.h"
#include "Sprite.h"
#include "Player.h"
#include "Background.h"
#include "Hotdog.h"
#include "Hamburger.h"
#include "Car1.h"
#include "Car2.h"
#include "Footballer.h"
#include "SpriteGenerator.h"
#include "Timer.h"
#include "Football.h"
#include "FootballPowerup.h"
#include "Squirrel.h"
#include "Can.h"
#include "Level.h"
#include "SoundClass.h"
#include "FinalScreen.h"
using namespace std;

int main(int argc, const char * argv[]) {
  

	SDLClass mySDL; //initialize SDL

	srand(time(NULL)); //seed srand

	//instantiate three backgrounds
	OpeningScreen myOpening(mySDL);
	Background myScrolling(mySDL);
	FinalScreen myFinalScreen(mySDL);

	StaticScreen *screenPtr; //pointer to current screen
	Player *playerPtr; //pointer to player
	screenPtr=&myOpening; //set screen pointer to address of first background
	playerPtr=NULL; //player pointer is NULL at first

	Player simpleMan(mySDL); //instantiate player
	vector<Sprite*> enemies;	//takes in pointers to all enemy objects
	SpriteGenerator enemyFactory(mySDL);	//generates random enemies
	vector<SpriteType> desiredEnemies; //vector of desired types of enemies, which will change based on the level

	vector<Sprite*> powerups; //vector of powerups
	SpriteGenerator powerupFactory(mySDL); //generates random powerups
	vector<SpriteType> desiredPowerups; //vector of desired types of powerups, which will change based on the level

	vector<Football> footballs; //vector footballs that player has thrown

	//Sound loading
	vector<SoundClass> songVector; //Vector of background songs
	SoundClass theme("GOT.wav",1); // Game of thrones theme
	SoundClass song1("UptownFunk.wav",1); //List of Songs
	SoundClass song2("Anaconda.wav",1);
	SoundClass song3("RatherBe.wav",1);
	SoundClass song4("TalkDirty.wav",1);
	SoundClass song5("DarkHorse.wav",1);
	SoundClass song6("Geronimo.wav",1);
	SoundClass song7("JessiesGirl.wav",1);
	SoundClass song8("ShutUpAndDance.wav",1);
	SoundClass death("NeverGonnaGiveYouUp.wav",1);
	SoundClass winSong("DontStopBelieving.wav",1); //winning song
	songVector.push_back(song1);//push songs into vector
	songVector.push_back(song2);
	songVector.push_back(song3);
	songVector.push_back(song4);
	songVector.push_back(song5);
	songVector.push_back(song6);
	songVector.push_back(song7);
	songVector.push_back(song8);

	int song = rand() % songVector.size(); //randomize


	theme.play(); //play theme song

	//vector of levels
	int lengthOfLevel = 1500; //length of each level
	int level = 0; //initial level zero
	vector<Level> levelVector; //level vector	
	Level level1(1); // declare levels
	Level level2(2);
	Level level3(3);
	levelVector.push_back(level1); //push level
	levelVector.push_back(level2);
	levelVector.push_back(level3);
	Timer levelTimer; //level timer - counts down - once time is up, progress to next level
	levelTimer.setTimeIncrement(2); //set increment
	levelTimer.addTime(); //add time to timer
	levelTimer.setTimeIncrement(lengthOfLevel); // set increment
        levelTimer.updateTime(); //update time
	vector<int> freqPowerUp; //getting frequency of powerups - range of iterations
	vector<int> freqEnemy; //geting frequency of enemies - range of iterations

	int screenState=0; //keeps track of screen

	//boolean values to keep track of game
	bool win=0;	
	bool lose=0;
	bool quit=false;

	SDL_Event e; //event handler

	while (!quit) //loops while the user does not quit
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type==SDL_QUIT) //quit if user hits red 'x'
			{
				quit=true;
			}

			else if (e.type==SDL_KEYDOWN) //user presses a key
			{
				//if any key is pressed for first screen state, go to next screenState
				if (screenState<1)
				{
					screenState++;
					theme.stop(); //stop theme when man starts to walk
					songVector[song].play(); //play random song
				}
					
				switch (screenState) {
					case 0:
						break;
						
					case 1:
						screenPtr=&myScrolling; //screen is now background for side scroller
						playerPtr=&simpleMan; //playerPtr points to player
						break;
					default:
						break;
				}

				switch(e.key.keysym.sym) //case checks which key was pressed
				{
					//user presses right -- if screen state is 1, player walks right
					case SDLK_d:
						if (screenState==1)
						{
							playerPtr->setState(isWalking);
							playerPtr->setFacingRight(1); //player should face right
						}
						break;

						//user presses left -- if screen state is 1, player walks left
					case SDLK_a:
						if (screenState==1)
						{
							playerPtr->setState(isWalking);
							playerPtr->setFacingRight(0); //player should face left
						}
						break;

					case SDLK_SPACE: //user presses space
						if (screenState==1) //if screen state is 1 and player has a football, instantiate/throw football
						{
							if (playerPtr->getNumFootballs()) //check if player has a football
							{
								Football footballSprite(mySDL, playerPtr->getXPos() + playerPtr->getW(), playerPtr->getYPos()); //instantiate football
								footballs.push_back(footballSprite); //add to vector of footballs
								playerPtr->setNumFootballs(0); //set player's number of footballs to 0
							}
						}

						if (screenState==2) //if screen state is 2, reset different variables so that game can restart
						{
							screenState=1; //set screen state to 1
							enemies.clear(); //clear vector of enemies
							powerups.clear(); //clear vector of powerups
							playerPtr->resetPlayer(); //reset different member variables in player
							screenPtr=&myScrolling; //set screen back to scrolling screen
							level=0; //set level to 0
							screenPtr->displayGameOver(0); //remove words displaying "game over"
							winSong.stop(); //stop win song
							death.stop(); //stop death song
							song = rand() % songVector.size(); //randomize
							songVector[song].play(); //start new random song
							footballs.clear(); //clear vector of footballs
							desiredEnemies.clear(); //clear vector of desired enemies
							desiredPowerups.clear(); //clear vector of desired powerups
							enemyFactory.setSprites(desiredEnemies);
							powerupFactory.setSprites(desiredPowerups);
							//reset levelTimer
							levelTimer.setTime(2);
							levelTimer.updateTime();
						}
						break;

					case SDLK_w: //if w is pressed, player jumps
						if (screenState==1 && playerPtr->getJumpingState()==isNotJumping)
						{
							playerPtr->setJumpingState(isJumpingUp);
						}
						break;

					default:
						break;
				}
			}

			else if (e.type==SDL_KEYUP)
			{
				switch(e.key.keysym.sym)
				{
					//stop player moving if player releases right or left button (a or d)
					case SDLK_d:
						if (screenState==1)
						{
							playerPtr->setState(isResting);
						}
						break;
					case SDLK_a:
						if (screenState==1)
						{
							playerPtr->setState(isResting);
						}
						break;
					default:
						break;
				}
			}

		}

		screenPtr->draw(); //draw background
		if (screenState==1 && playerPtr!=NULL)
		{
			if (win==1 || lose==1) //if player has just won or lost, display level (1) and set win and lose to 0
			{
				screenPtr->displayLevel(level);
				win=0;
				lose=0;
			}

			if (levelTimer.getTimeIsUp()) //if timer is up
			{
				level++;//increment level
                                screenPtr->displayLevel(level); //display level in top corner
				switch (level) //do different things for each level
				{
					case 1:
						levelTimer.addTime(); //add time to timer
                                                desiredEnemies.push_back(isCar1); //add yellow car to level 1 
                                                desiredEnemies.push_back(isFootballer); // add football player to level one
                                                desiredEnemies.push_back(isSquirrel); //add squirrel to level one
                                                desiredPowerups.push_back(isHamburger); //add hamburger to level one
                                                desiredPowerups.push_back(isFootballPowerup); //add football powerup
						break;

					case 2:
						levelTimer.addTime(); //add time
                                                desiredEnemies.push_back(isCan);//add can
                                                desiredPowerups.push_back(isHotdog);//add hotdog
						break;

					case 3:
						levelTimer.addTime();//add time
                                                desiredEnemies.push_back(isCar2);//add red car
						break;
					case 4:
						songVector[song].stop(); //stop background when player wins 
						winSong.play(); //play win song
						win=1; //set win equal to one
						screenState++; //increment screenstate
						screenPtr=&myFinalScreen; //set screen pointer to address of final screen
						break;


				}

				if (level<=3)
				{
					freqPowerUp = levelVector[level-1].getFrequencyPowerUp(); //set frequency of powerup
					powerupFactory.setFrequency(freqPowerUp[0],freqPowerUp[1]); 
					freqEnemy = levelVector[level-1].getFrequencyEnemy();//set frequency of enemy
					enemyFactory.setFrequency(freqEnemy[0], freqEnemy[1]);
					enemyFactory.setSprites(desiredEnemies);//set desired enemies
					powerupFactory.setSprites(desiredPowerups);//set desired powerups
				}
			}
			
			//update levelTimer only if player is walking to the right
                        if (playerPtr->getState() == isWalking && playerPtr->getFacingRight()) 
			    levelTimer.updateTime();
			playerPtr->update(); //update player
			playerPtr->collisionLoopRect(enemies); //check if player is colliding with enemies
			playerPtr->collisionLoopRect(powerups); //check if powerups colliding with player
			
			//draw footballs that the player has thrown
			for (int i=0; i<footballs.size(); i++)
			{
                                int ballX = footballs[i].getX();
                                int playerX = playerPtr->getX();
                                int screenW = mySDL.getW();
				if (footballs[i].collisionLoopRect(enemies) || ballX < (playerX-screenW) || ballX > (playerX+screenW))
				{
					//if collision with footballer occurs, destroy football and delete from vector
                                        //also if football goes off the screen
					footballs[i].destroySprite();
					footballs.erase(footballs.begin()+i);
					i--;
				}
			}

			if (!playerPtr->isDead()) //if player is not dead
			{
				//use stopScreen variable to determine if screen should scroll
				screenPtr->setIsScrolling(!playerPtr->getStopScreen());
				screenPtr->setSpeed(playerPtr->getSpeedX()); //set speed of screen based on speed of player
				screenPtr->getTexture(2)->setDraw(playerPtr->getNumFootballs()); //if player has football, draw football in corner to let user know

				playerPtr->draw(); //draw player

				enemyFactory.generateSprites(playerPtr); //generate random enemies
				enemyFactory.packageSprites(enemies); 
				powerupFactory.generateSprites(playerPtr); //generate random powerups
				powerupFactory.packageSprites(powerups);
			
				//draw enemies based on the speed of the player
				for (int i=0; i < enemies.size(); i++)
				{
					if (screenPtr->getIsScrolling())
					{
						enemies[i]->draw(playerPtr->getSpeedX());	// when standing still, must scroll when screen does
				
					}

					else
					{
						enemies[i]->draw(0);
					}
				}

				//draw powerups based on the speed of the player
				for (int i=0; i < powerups.size(); i++)
				{
					if (screenPtr->getIsScrolling())
					{
						powerups[i]->draw(playerPtr->getSpeedX());	// when standing still, must scroll when screen does
				
					}

					else
					{
						powerups[i]->draw(0);
					}
				}

				//draw footballs that player has thrown
				for (int i=0; i<footballs.size(); i++)
				{
					footballs[i].draw(1);
				}
			}


			else //if player is dead, destroy sprite and switch screen states
			{
				screenState=2;
				lose=1;
				screenPtr->displayGameOver(1);
				songVector[song].stop(); //stop background song
				death.play(); //play death song
			}

			enemyFactory.destroyPastSprites(playerPtr,enemies);		// dynamically delete sprites too  far off the screen
		        powerupFactory.destroyPastSprites(playerPtr,powerups);
		}

		mySDL.update();		// not included in draw() b/c only need one update at the end
	}

	//after game loop, destroy footballs, enemies, and powerups
	
	for (int i=0; i<footballs.size(); i++)
	{
		footballs[i].destroySprite();
	}

	for (int i=0; i<enemies.size(); i++)
	{
		enemies[i]->destroySprite();
	}

	for (int i=0; i<powerups.size(); i++)
	{
		powerups[i]->destroySprite();
	}
    return 0;
}
