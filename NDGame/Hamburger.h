/* Base Hamburger derived from Sprite Class */
#ifndef HAMBURGER_H
#define HAMBURGER_H

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

class Hamburger : public Sprite {

	public: 
		Hamburger(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(int); //takes speed of scrolling background remain still relative to it		
			
};

#endif
