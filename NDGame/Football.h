// Football derived from Sprite Class
#ifndef FOOTBALL_H
#define FOOTBALL_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "LTexture.h"
#include "SDLClass.h"
#include "Sprite.h"
using namespace std;

class Football : public Sprite {

	public:
		Football(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(int); //1 if moving 0 if not
};

#endif
