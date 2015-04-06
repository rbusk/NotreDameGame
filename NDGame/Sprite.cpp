/* implementation file for Sprite class */

#include "Sprite.h"

//constructor assigns pointer to SDLClass
Sprite::Sprite(SDLClass &myC)
{
	height = 0;
	width = 0;
	xPos = 0;
	yPos = 0;
	currentClip=0;
	state = isResting;
	jumpingState = isNotJumping;
	mySDL=&myC;
}

Sprite::~Sprite()
{
	destroySprite();
}

void Sprite::loadFromFile(string path)
{
	spriteSheet = mySDL->loadFromFile(path);
}
//update screen
void Sprite::draw()
{
	switch (jumpingState)
	{
		case isJumpingUp:
			yPos-=4;
			if (yPos<maxHeight)
			{
				jumpingState=isJumpingDown;
			}
			break;
		case isJumpingDown:
			yPos+=4;
			if (yPos>minHeight)
			{
				jumpingState=isNotJumping;
			}
			break;
		default:
			break;

	}
	
	SDL_Rect* thisClip = &spriteClips[currentClip/numOfClips];
	mySDL->renderSprite(spriteSheet,xPos,yPos,thisClip);

	if (state==isWalking)
		currentClip++;

	if (currentClip / numOfClips >= numOfClips)
		currentClip = 0;
	
}

void Sprite::destroySprite() 
{
	spriteSheet.free();
	spriteClips.clear();
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

void Sprite::setState(int n)
{
	state=n;
}

void Sprite::setMaxHeight(int n)
{
	maxHeight=n;
}

void Sprite::setMinHeight(int n)
{
	minHeight=n;
}

int Sprite::getState()
{
	return state;
}

int Sprite::getJumpingState()
{
	return jumpingState;
}

void Sprite::setJumpingState(int n)
{
	jumpingState=n;
}
