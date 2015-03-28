/* StaticScreen displaying graduating diploma*/
#ifndef GRADUATINGSCREEN_H
#define GRADUATINGSCREEN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
#include "StaticScreen.h"
using namespace std;

class GraduatingScreen : public StaticScreen {

	public: 
		GraduatingScreen(SDLClass &myC);
};

#endif
