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
	facingRight=1;
	mySDL=&myC;
	stopScreen=1;
}

Sprite::~Sprite()
{
	destroySprite();
}

void Sprite::loadSheetFromFile(string path)
{
	spriteSheet = mySDL->loadFromFile(path);
}

void Sprite::loadFlippedSheetFromFile(string path)
{
	flippedSheet = mySDL->loadFromFile(path);
}

void Sprite::update()
{
	//if facing left, stop screen
	if (!facingRight && xPos>=0)
	{
		stopScreen=1;
	}

	//if facing right but position is too far left, stop screen
	else if (facingRight && xPos<getHalfOfScreen())
	{
		stopScreen=1;
	}

	//otherwise screen should scroll if sprite is walking
	else if (state==isWalking)
	{
		stopScreen=0;
	}

	//otherwise stop screen
	else
	{
		stopScreen=1;
	}

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

	//if sprite is facing right
	if (facingRight==1)
	{
		SDL_Rect* thisClip = &spriteClips[currentClip/numOfClips];
		mySDL->renderSprite(spriteSheet,xPos,yPos,thisClip);
	}

	//if sprite is facing left
	else
	{
		SDL_Rect* thisClip = &flippedClips[currentClip/numOfClips];
		mySDL->renderSprite(flippedSheet,xPos,yPos,thisClip);
	}

	//if isWalking, increment clip
	if (state==isWalking)
	{
		currentClip++;

		//if facing left, character must move left (rather than the screen scrolling)
		//but also can't let character fall of screen
		if (!facingRight && xPos>=4)
		{
			xPos-=4;
		}

		//if facing right but position is too far left, increment x position
		else if (facingRight && xPos<getHalfOfScreen())
		{
			xPos+=4;
		}

	}

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

void Sprite::addFlippedClip(int cx, int cy, int cw, int ch)
{
	flippedClips.push_back(SDL_Rect());
	int index = flippedClips.size() - 1;
	flippedClips[index].x = cx;
	flippedClips[index].y = cy;
	flippedClips[index].w = cw;
	flippedClips[index].h = ch;
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

void Sprite::setFacingRight(int n)
{
	facingRight=n;
}

int Sprite::getHalfOfScreen()
{
	return mySDL->getW()/2;
}

int Sprite::getStopScreen()
{
	return stopScreen;
}
