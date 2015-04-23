#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "LTexture.h"
#include "StaticScreen.h"
#include "OpeningScreen.h"
#include "GraduatingScreen.h"
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
using namespace std;

int main(int argc, const char * argv[]) {
  

	SDLClass mySDL;

	OpeningScreen myOpening(mySDL);
//	GraduatingScreen myGraduating(mySDL);
	Background myScrolling(mySDL);
	StaticScreen *screenPtr;
	Player *playerPtr;
	screenPtr=&myOpening;
	playerPtr=NULL;

	Player simpleMan(mySDL);
	vector<Sprite*> enemies;	//takes in pointers to all enemy objects
	SpriteGenerator enemyFactory(mySDL);	
	vector<SpriteType> desiredEnemies;

	vector<Sprite*> powerups;
	SpriteGenerator powerupFactory(mySDL);
	vector<SpriteType> desiredPowerups;

	//vector of footballs that player has thrown
	vector<Football> footballs;

	//opening song
	SoundClass main("GOT.wav",1);

	//vector of levels
	int lengthOfLevel = 1000;
	int level = 0;
	vector<Level> levelVector;	
	Level level1(1);
	Level level2(2);
	Level level3(3);
	levelVector.push_back(level1);
	levelVector.push_back(level2);
	levelVector.push_back(level3);
	Timer levelTimer;
	levelTimer.setTimeIncrement(1);
	levelTimer.addTime();
	levelTimer.setTimeIncrement(lengthOfLevel);
	levelTimer.updateTime();
	vector<int> freqPowerUp;
	vector<int> freqEnemy;

	cout << levelTimer.getTime() << endl;
	cout << levelTimer.getTimeIsUp() << endl;


	int screenState=0;
	
	bool quit=false;

	SDL_Event e; //event handler

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type==SDL_QUIT)
			{
				quit=true;
			}

			else if (e.type==SDL_KEYDOWN) //user presses a key
			{
				//if any key is pressed for first 2 screenStates, go to next screenState and set some pointers
				if (screenState<1)
				{
					screenState++;
					
					switch (screenState) {
						case 0:
							break;
							
						case 1:
							main.play();
							screenPtr=&myScrolling;
							playerPtr=&simpleMan;
							break;
						default:
							break;
					}
				}

				switch(e.key.keysym.sym) //case checks which key was pressed
				{
					//user presses right -- if screen state is 2, player walks right
					case SDLK_RIGHT:
						if (screenState==1)
						{
							playerPtr->setState(isWalking);
							playerPtr->setFacingRight(1); //player should face right
						}
						break;

						//user presses left -- if screen state is 2, player walks left
					case SDLK_LEFT:
						if (screenState==1)
						{
							playerPtr->setState(isWalking);
							playerPtr->setFacingRight(0);
						}
						break;

					case SDLK_SPACE:
						if (screenState==1)
						{
							if (playerPtr->getNumFootballs())
							{
								Football footballSprite(mySDL, playerPtr->getXPos() + playerPtr->getW(), playerPtr->getYPos());
								footballs.push_back(footballSprite);
								playerPtr->setNumFootballs(0);
							}
						}
						break;

					case SDLK_UP:
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
					//stop player moving if player releases right or left button
					case SDLK_RIGHT:
						if (screenState==1)
						{
							playerPtr->setState(isResting);
						}
						break;
					case SDLK_LEFT:
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

		screenPtr->draw();
		if (screenState==1 && playerPtr!=NULL)
		{

			if (levelTimer.getTimeIsUp())
			{
				level++;
				switch (level)
				{
					case 1:
						levelTimer.addTime();
						break;

					case 2:
						levelTimer.addTime();
						break;

					case 3:
						levelTimer.addTime();
						break;

				}
				freqPowerUp = levelVector[level-1].getFrequencyPowerUp();
				cout << freqPowerUp[0] << freqPowerUp[1] << endl;
				powerupFactory.setFrequency(freqPowerUp[0],freqPowerUp[1]);
				freqEnemy = levelVector[level-1].getFrequencyEnemy();
				cout << freqEnemy[0] << freqEnemy[1] << endl;
				enemyFactory.setFrequency(freqEnemy[0], freqEnemy[1]);
			}
			
			levelTimer.updateTime();
			cout << levelTimer.getTime() << endl;
			cout << level << endl;
			playerPtr->update();

			playerPtr->collisionLoopRect(enemies);
			playerPtr->collisionLoopRect(powerups);
			
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

			if (!playerPtr->isDead())
			{
				//use stopScreen variable to determine if screen should scroll
				screenPtr->setIsScrolling(!playerPtr->getStopScreen());
				screenPtr->setSpeed(playerPtr->getSpeedX());
				screenPtr->getTexture(2)->setDraw(playerPtr->getNumFootballs());


				playerPtr->draw();
			
				// probably put in timer based if statements to change these after so long
				//enemyFactory.setFrequency(200, 300);
				//powerupFactory.setFrequency(100,200);

				desiredEnemies.clear();

				//desiredEnemies.push_back(isCar1);
				//desiredEnemies.push_back(isCar2);
				desiredEnemies.push_back(isFootballer);
				desiredEnemies.push_back(isSquirrel);
                                desiredEnemies.push_back(isCan);
				desiredPowerups.clear();
				desiredPowerups.push_back(isHamburger);
				desiredPowerups.push_back(isHotdog);
				desiredPowerups.push_back(isFootballPowerup);

				enemyFactory.setSprites(desiredEnemies);
				enemyFactory.generateSprites(playerPtr);
				enemyFactory.packageSprites(enemies);
				powerupFactory.setSprites(desiredPowerups);
				powerupFactory.generateSprites(playerPtr);
				powerupFactory.packageSprites(powerups);
			

				for (int i=0; i < enemies.size(); i++)
				{
					//enemies[i]->setSpeed(playerPtr->getSpeedX()/2, enemies[i]->getSpeedY());
					if (screenPtr->getIsScrolling())
					{
						enemies[i]->draw(playerPtr->getSpeedX());	// when standing still, must scroll when screen does
				
					}

					else
					{
						enemies[i]->draw(0);
					}
				}

				for (int i=0; i < powerups.size(); i++)
				{
					//powerups[i]->setSpeed(playerPtr->getSpeedX()/2, playerPtr->getSpeedY()/2);
					//powerups[i]->draw(screenPtr->getIsScrolling());	// when standing still, must scroll when screen does
					if (screenPtr->getIsScrolling())
					{
						powerups[i]->draw(playerPtr->getSpeedX());	// when standing still, must scroll when screen does
				
					}

					else
					{
						powerups[i]->draw(0);
					}
				}

				for (int i=0; i<footballs.size(); i++)
				{
					footballs[i].draw(1);
				}
			}


			else //if player is dead, destroy sprite and switch screen states
			{
				screenState=2;
				screenPtr->displayGameOver();
			}

			enemyFactory.destroyPastSprites(playerPtr,enemies);		// dynamically delete sprites too 
		}															// far off the screen

		mySDL.update();		// not included in draw() b/c only need one update at the end
	}

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
