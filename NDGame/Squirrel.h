#ifndef SQUIRREL_H
#define SQUIRREL_H

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
#include "Sprite.h"
using namespace std;

class Squirrel : public Sprite {

	public: Squirrel(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(int);
};

#endif
