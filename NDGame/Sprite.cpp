/* implementation file for Sprite class */

#include "Sprite.h"

//constructor assigns pointer to SDLClass
Sprite::Sprite(SDLClass &myC)
{
	height = 0;
	width = 0;
	xPos = 0;
	yPos = 0;
	mySDL=&myC;
}

Sprite::~Sprite()
{
	//destroySprite();
}

void Sprite::loadFromFile(string path)
{
	spriteSheet = mySDL->loadFromFile(path);
}
//update screen
void Sprite::draw()
{
	/*
		Steps to possibly create this function:
		1. Create new render function in LTexture that also takes in x, y, and clip
		   proportions as seen in Lazy Foo tutorial #11 possible called renderClip()

		2. Then create new wrapper function in SDLClass similar to renderTextures()
		   that will be specific to the above LTexture function. Possible called renderSprites()

		3. After all of that is working and we can render a still-sprite, then we can finally 
		   implement this function such that it will cycle through clips will bool isAnimated = true
		   with the class variables currentClip, numOfClips, etc.
	*/
	
	SDL_Rect* thisClip = &spriteClips[currentClip/numOfClips];
	mySDL->renderSprite(spriteSheet,xPos,yPos,thisClip);

	if (isAnimated)
		currentClip++;

	if (currentClip / numOfClips >= numOfClips)
		currentClip = 0;
	
}

void destroySprite() 
{
	//spriteSheet.free();
	//spriteClips.clear();
}

int Sprite::getX() 
{
	return xPos;
}

int Sprite::getY() 
{
	return yPos;
}

void Sprite::setPos(int x, int y)
{
	xPos = x;
	yPos = y;
}

int Sprite::getH()
{
	return height;
}

int Sprite::getW()
{
	return width;
}

void Sprite::setSize(int w, int h)
{
	width = w;
	height = h;
}

void Sprite::setNumClips(int total)
{
	numOfClips = total;
}

void Sprite::addClip(int cx, int cy, int cw, int ch)
{
	spriteClips.push_back(SDL_Rect());
	int index = spriteClips.size() - 1;
	spriteClips[index].x = cx;
	spriteClips[index].y = cy;
	spriteClips[index].w = cw;
	spriteClips[index].h = ch;
}

void Sprite::setCurrentClip(int n) 
{
	currentClip = n;
}

