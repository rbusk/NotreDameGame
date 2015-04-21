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
#include "EnemyGenerator.h"
#include "Timer.h"
#include "Football.h"
#include "FootballPowerup.h"
#include "Can.h"
using namespace std;

int main(int argc, const char * argv[]) {
  

	SDLClass mySDL;

	OpeningScreen myOpening(mySDL);
	GraduatingScreen myGraduating(mySDL);
	Background myScrolling(mySDL);

	Player simpleMan(mySDL);
	Hotdog dog(mySDL);
	Hamburger burger(mySDL);
	FootballPowerup football(mySDL);

	StaticScreen *screenPtr;
	Player *playerPtr;
	Hotdog *dogPtr;
	Hamburger *burgerPtr;
	FootballPowerup *footballPtr;

	//can enemy
	Can can(mySDL);
	Can *canPtr;
	canPtr=&can;

	//the screen sort of works if these are here idk man
	Can can2(mySDL);
	Can *can2ptr;

	screenPtr=&myOpening;
	playerPtr=NULL;
	dogPtr =&dog;
	burgerPtr = &burger;
	
	footballPtr=&football;


	vector<Sprite*> enemies;	//takes in pointers to all enemy objects
	enemies.push_back(dogPtr);
	enemies.push_back(burgerPtr);
	enemies.push_back(footballPtr);
	enemies.push_back(canPtr);

	EnemyGenerator enemyFactory(mySDL);
	vector<EnemyType> desiredEnemies;

	//vector of footballs that player has thrown
	vector<Football> footballs;


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
				if (screenState<2)
				{
					screenState++;
					
					switch (screenState) {
						case 0:
							break;
							
						case 1:
							screenPtr=&myGraduating;
							break;
						case 2:
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
						if (screenState==2)
						{
							playerPtr->setState(isWalking);
							playerPtr->setFacingRight(1); //player should face right
						}
						break;

						//user presses left -- if screen state is 2, player walks left
					case SDLK_LEFT:
						if (screenState==2)
						{
							playerPtr->setState(isWalking);
							playerPtr->setFacingRight(0);
						}
						break;

					case SDLK_SPACE:
						if (screenState==2)
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
						if (screenState==2 && playerPtr->getJumpingState()==isNotJumping)
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
						if (screenState==2)
						{
							playerPtr->setState(isResting);
						}
						break;
					case SDLK_LEFT:
						if (screenState==2)
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
		if (screenState==2 && playerPtr!=NULL)
		{
			playerPtr->update();

			playerPtr->collisionLoopRect(enemies);
			
			for (int i=0; i<footballs.size(); i++)
			{
				if (footballs[i].collisionLoopRect(enemies))
				{
					//if collision with footballer occurs, destroy football and delete from vector
					footballs[i].destroySprite();
					footballs.erase(footballs.begin()+i);
					i--;
				}
			}

			if (!playerPtr->isDead())
			{
				//use stopScreen variable to determine if screen should scroll
				screenPtr->setIsScrolling(!playerPtr->getStopScreen());
				screenPtr->setSpeed(playerPtr->getSpeedX()/2);
				screenPtr->getTexture(2)->setDraw(playerPtr->getNumFootballs());


				playerPtr->draw();
			
				// probably put in timer based if statements to change these after so long
				int numOfEnemies = 3;	// desired number of enemies
				enemyFactory.setFrequency(numOfEnemies);

				desiredEnemies.clear();
				//desiredEnemies.push_back(isCar1);
				//desiredEnemies.push_back(isCar2);
				desiredEnemies.push_back(isFootballer);

				enemyFactory.setEnemies(desiredEnemies);

				if (enemies.size() < numOfEnemies)
				{
					enemyFactory.generateSprites(playerPtr,numOfEnemies - enemies.size());
					enemyFactory.packageSprites(enemies);
				}
			

				for (int i=0; i<enemies.size(); i++)
				{
					enemies[i]->setSpeed(playerPtr->getSpeedX()/2, playerPtr->getSpeedY()/2);
					enemies[i]->draw(screenPtr->getIsScrolling());	// when standing still, hotdog must scroll when screen does
				}

				for (int i=0; i<footballs.size(); i++)
				{
					footballs[i].draw(1);
				}
			}


			else //if player is dead, destroy sprite and switch screen states
			{
				screenState=3;
				screenPtr->displayGameOver();
			}
		}

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

    	return 0;
}
