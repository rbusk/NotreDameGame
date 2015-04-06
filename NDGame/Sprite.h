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

enum SpriteStates {
	isResting, //use first two for state variable
	isWalking,
	isNotJumping, //use the next three for jumpingState member variable
	isJumpingUp,
	isJumpingDown
};

class Sprite {
	
	public:
		Sprite(SDLClass &myC);
		~Sprite();
		virtual void setTextureClips(string path)=0;
		void loadFromFile(string path);
		void draw();
		void destroySprite();
		int getX();
		int getY();
		void setPos(int x, int y);
		int getH();
		int getW();
		void setSize(int w, int h);
		void setNumClips(int);
		void addClip(int, int, int, int);
		void setCurrentClip(int);
		void setState(int);
		void setMaxHeight(int);
		void setMinHeight(int);
		int getState();
		int getJumpingState();
		void setJumpingState(int);

	private:
		LTexture spriteSheet;	
		vector<SDL_Rect> spriteClips;
		string texturePath;	
		int numOfClips;
		int currentClip;
		int xPos;
		int yPos;
		int maxHeight; //max jumping height
		int minHeight; //min jumpingheight
		int height;
		int width;
		int state; // isResting, isWalking, or isJumping
		int jumpingState; //3 states- not, up, down
		SDLClass *mySDL;
};

#endif
