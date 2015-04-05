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
	spriteSheet=mySDL->loadFromFile("resources/manSpriteSheet.jpg");
}

Sprite::~Sprite()
{
//	destroySprite();
}


void Sprite::setTextureClips(string path)
{
	/* 
	   Will probably be a virtual function because each version of 
	   this will be very specific to the sprite's sprite sheet
	 */
	//spriteSheet=mySDL->loadFromFile(path);
	//for (int cntr = 0; cntr < n; cntr++) {
	//	runSpriteClips.push_back(SDL_Rect());
	//	runSpriteClips[cntr].x = cntr*newTexture.getWidth()/n;
	//	runSpriteClips[cntr].y = 0;
	//	runSpriteClips[cntr].w = newTexture.getWidth();
	//	runSpriteClips[cntr].h = newTexture.getHeight();
	//}
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
	//mySDL->clear();
	//while (currentClip < 4){
	//	SDL_Rect* currentClip = &spriteClips[frame/numOfRunFrames];
	//	runSpriteSheet.render(myRenderer,x,y,currentClip);
	//	mySDL->update();
	//}

	//mySDL->renderTextures(spriteSheet);
	//mySDL->update();

	SDL_Rect frame;
	frame.x = 0;
	frame.y = 0;
	frame.w = 194;
	frame.h = 198;
	SDL_Rect* currentClip = &frame;
	mySDL->renderSprite(spriteSheet,100,100,currentClip);
	//mySDL->update();
}

void destroySprite() 
{
//	spriteSheet.free();
//	spriteClips.clear();
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

