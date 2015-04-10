/* Base Hotdog derived from Sprite Class */
#ifndef HOTDOG_H
#define HOTDOG_H

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

class Hotdog : public Sprite {

	public: 
		Hotdog(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(int); //draw sprite
		void setIsLoaded(bool);


	private:
		bool isLoaded; // if true, then will be on screen		
			
};

#endif
