/* StaticScreen for opening menu*/
#ifndef FINALSCREEN_H
#define FINALSCREEN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
#include "StaticScreen.h"
using namespace std;

class FinalScreen : public StaticScreen {

	public: 
		FinalScreen(SDLClass &myC);
};

#endif
