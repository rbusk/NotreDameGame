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
using namespace std;

int main(int argc, const char * argv[]) {
  

	SDLClass mySDL;

	OpeningScreen myOpening(mySDL);
	GraduatingScreen myGraduating(mySDL);
	Background myScrolling(mySDL);

	Player simpleMan(mySDL);
	Hotdog dog(mySDL);

	StaticScreen *screenPtr;
	Player *playerPtr;
	Hotdog *dogPtr;

	screenPtr=&myOpening;
	playerPtr=NULL;
	dogPtr =&dog;

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

			//use stopScreen variable to determine if screen should scroll
			screenPtr->setIsScrolling(!playerPtr->getStopScreen());

			playerPtr->draw();

			if (screenPtr->getIsScrolling())		// when standing still, hotdog must scroll when screen does
				dogPtr->draw(2);				// thus this value is the "offset" found in a scrolling background
			else
				dogPtr->draw(0);
		}

		mySDL.update();		// not included in draw() b/c only need one update at the end
	}

    return 0;
}
