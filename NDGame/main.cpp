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
using namespace std;

int main(int argc, const char * argv[]) {
  

	SDLClass mySDL;

	OpeningScreen myOpening(mySDL);
	GraduatingScreen myGraduating(mySDL);

	Player simpleMan(mySDL);

	StaticScreen *screenPtr;
	Player *playerPtr;

	screenPtr=&myOpening;
	playerPtr=&simpleMan;

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
				screenState++;
			}
		}

		switch (screenState) {
			case 0:
				break;
				
			case 1:
				screenPtr=&myGraduating;
				break;
			default:
				quit=true;
		}

		screenPtr->draw();
		playerPtr->draw();
		mySDL.update();		// not included in draw() b/c only need one update at the end
	}

    return 0;
}
