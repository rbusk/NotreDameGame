// Football powerup derived from Sprite Class
#ifndef FOOTBALLPOWERUP_H
#define FOOTBALLPOWERUP_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "LTexture.h"
#include "SDLClass.h"
#include "Sprite.h"
using namespace std;

class FootballPowerup : public Sprite {

	public:
		FootballPowerup(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(int); //1 if moving 0 if not
};

#endif
