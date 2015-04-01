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

	private:
		vector<LTexture> textures;
		SDLClass *mySDL;
};

#endif
