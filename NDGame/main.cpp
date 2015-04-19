#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "LTexture.h"
#include "SDLClass.h"
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
using namespace std;

int main(int argc, const char * argv[]) {
  

	SDLClass mySDL;

	OpeningScreen myOpening(mySDL);
	GraduatingScreen myGraduating(mySDL);
	Background myScrolling(mySDL);

	Player simpleMan(mySDL);
	/*Hotdog dog(mySDL);
	Hamburger burger(mySDL);
	Car1 car1(mySDL);
	Car2 car2(mySDL);
	Footballer baller(mySDL);*/

	StaticScreen *screenPtr;
	Player *playerPtr;
	/*Hotdog *dogPtr;
	Hamburger *burgerPtr;
	Car1 *car1Ptr;
	Car2 *car2Ptr;
	Footballer *ballerPtr;*/

	screenPtr=&myOpening;
	playerPtr=NULL;
	/*dogPtr =&dog;
	burgerPtr = &burger;
	car1Ptr=&car1;
	car2Ptr=&car2;
	ballerPtr=&baller;*/

	vector<Sprite*> enemies;	//takes in pointers to all enemy objects
	/*enemies.push_back(dogPtr);
	enemies.push_back(burgerPtr);
	enemies.push_back(car1Ptr);
	enemies.push_back(car2Ptr);
	enemies.push_back(ballerPtr);*/
	EnemyGenerator enemyFactory(mySDL);
	vector<EnemyType> desiredEnemies;

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

						//user presses space -- switch screenState
					case SDLK_SPACE:
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
						playerPtr->setState(isResting);
						break;
					case SDLK_LEFT:
						playerPtr->setState(isResting);
						break;
					default:
						break;
				}
			}

		}

		screenPtr->draw();
		if (playerPtr!=NULL)
		{
			playerPtr->update();

			//cout << "hi";
			if (enemies.size() > 0)
				playerPtr->collisionLoopRect(enemies);

			//use stopScreen variable to determine if screen should scroll
			screenPtr->setIsScrolling(!playerPtr->getStopScreen());

			playerPtr->draw();
			
			// probably put in timer based if statements to change these after so long
			int numOfEnemies = 3;	// desired number of enemies
			enemyFactory.setFrequency(numOfEnemies);

			desiredEnemies.clear();
			desiredEnemies.push_back(isCar1);
			desiredEnemies.push_back(isCar2);
			desiredEnemies.push_back(isFootballer);

			enemyFactory.setEnemies(desiredEnemies);

			if (enemies.size() < numOfEnemies)
				enemyFactory.generateSprites(playerPtr,numOfEnemies - enemies.size());
			enemyFactory.packageSprites(enemies);

			if (screenPtr->getIsScrolling())		
			{										
				for (int i=0; i < enemies.size(); i++)
				{
					enemies[i]->draw(2);	// when standing still, hotdog must scroll when screen does
				}
			}								// thus this value is the "offset" of 2 found in a scrolling background
			else
			{	
				for (int i=0; i < enemies.size(); i++)
					enemies[i]->draw(0);	
			}
		}

		mySDL.update();		// not included in draw() b/c only need one update at the end
	}

    return 0;
}
