/* StaticScreen for opening menu*/
#ifndef OPENINGSCREEN_H
#define OPENINGSCREEN_H

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

class OpeningScreen : public StaticScreen {

	public: 
		OpeningScreen(SDLClass &myC);
};

#endif
