/* Sprite class for the sprite that the user controls */

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
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
		virtual void setTextureClips(string path1, string path2)=0;
		void loadSheetFromFile(string path);
		void loadFlippedSheetFromFile(string path);
		void destroySprite();
		void addClip(int, int, int, int);
		void addFlippedClip(int, int, int, int);

		void basicDraw(); //basic drawing functionality that all sprites must use -- not directly used by user but used in draw function below
		void draw(); //uses basicDraw in base class and can be changed for derived classes
		void update(); //not all sprite classes may use this

		//change sprite's position
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

		void incrementCurrentClip(); 

		//get and set functions
		int getX();
		int getY();
		void setPos(int x, int y);
		int getH();
		int getW();
		void setSize(int w, int h);
		void setNumClips(int);
		void setCurrentClip(int);
		void setState(int);
		int getState();
		void setFacingRight(int);
		int getHalfOfScreen(); //return halfway point of screen in x direction
		int getFacingRight();
		int getXPos();
		int getYPos();
		int getSpeed();
		void setSpeed(int);
		int getCurrentClip();

	private:
		LTexture spriteSheet;	
		LTexture flippedSheet; //for when character walks the other way
		vector<SDL_Rect> spriteClips;
		vector<SDL_Rect> flippedClips; //for when character walks the other way

		SDLClass *mySDL;

		int height;
		int width;

		string texturePath;	
		int numOfClips;
		int currentClip;
		int xPos;
		int yPos;
		int speed;
		int state; // isResting, isWalking, or isJumping
		bool facingRight; //1 if walking right, 0 if walking left
};

#endif
