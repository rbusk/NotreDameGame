/* can derived from sprite class*/

#ifndef CAN_H
#define CAN_H

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

class Can : public Sprite {

	public:
		Can(SDLClass &myC);
		void setTextureClips(string path1, string path2);
		void draw(int);
};
#endif
