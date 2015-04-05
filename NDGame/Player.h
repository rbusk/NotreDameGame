/* Man derived from Sprite Class */
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
#include "Sprite.h"
using namespace std;

class Player : public Sprite {

	public: 
		Player(SDLClass &myC);
		void setTextureClips(string path);
};

#endif
