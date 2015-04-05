/* Sprite class for the sprite that the user controls */

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
using namespace std;

class Sprite {
	
	public:
		Sprite(SDLClass &myC);
		~Sprite();
		void setTextureClips(string path);
		void draw();
		void destroySprite();
		int getX();
		int getY();
		void setPos(int x, int y);
		int getH();
		int getW();
		void setSize(int w, int h);
		bool isAnimated;
		// add more as necessary once can render

	private:
		LTexture spriteSheet;	
		vector<SDL_Rect> spriteClips;	
		int numOfClips;
		int currentClip;
		int xPos;
		int yPos;
		int height;
		int width;
		SDLClass *mySDL;
};

#endif
