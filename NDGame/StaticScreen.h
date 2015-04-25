/* StaticScreen class for screens that don't change, like menu and instruction screens
 * this is a base class
 */

#ifndef STATICSCREEN_H
#define STATICSCREEN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "LTexture.h"
#include "SDLClass.h"
using namespace std;

enum ScrollingStates {
	isNotScrolling,
	isScrollingLeft,
	isScrollingRight
};

class StaticScreen {

	public: 
		StaticScreen(SDLClass &myC);
		~StaticScreen();
		void destroyScreen();
		void draw(); //update screen
		void loadFromFile(string path); //add texture from file
		void loadFromText(string textureText, SDL_Color textColor, TTF_Font*& gFont, int xIn, int yIn);
		int getSize();
		SDLClass * getSDL();
		void setIsScrolling(int x);
		void setIsScrollingScreen(int x);
		int getIsScrolling();
		void incrementSpeed(int);
		void setSpeed(int);
		void setScrollingOffset(int);
		LTexture* getTexture(int); //returns ptr LTexture w/ index of input
                void setTexture(LTexture, int);
		virtual void displayGameOver(); //only used for Background class
                virtual void displayLevel(int);
	private:
		vector<LTexture> textures;
		SDLClass *mySDL;
		int isScrollingScreen; //indicates if scrolling screen
		int isScrolling; //indicates if scrolling screen is scrolling-- use enums
		int scrollingOffset;
		int speed;
};

#endif
