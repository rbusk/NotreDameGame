/* implementation file for Sprite class */

#include "Sprite.h"
#include <SDL2/SDL.h>
using namespace std;
//constructor assigns pointer to SDLClass
Sprite::Sprite(SDLClass &myC)
{
	height = 0;
	width = 0;
	xPos = 0;
	yPos = 0;
	currentClip=0;
	state = isResting;
	facingRight=1;
	mySDL=&myC;
}

Sprite::~Sprite() 
{
	//DESTUCTION IMMINENT
        //A virtual function
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
}

void Sprite::draw(int s)
{
	basicDraw();
	checkCurrentClip();
}

//update screen
void Sprite::basicDraw()
{

	//if sprite is facing right
	if (facingRight==1)
	{
		SDL_Rect* thisClip = &spriteClips[currentClip/numOfClips];
		mySDL->renderSprite(spriteSheet,xPos,yPos,thisClip);
		spriteBox.w = thisClip->w;
		spriteBox.h = thisClip->h;
	}

	//if sprite is facing left
	else
	{
		SDL_Rect* thisClip = &flippedClips[currentClip/numOfClips];
		mySDL->renderSprite(flippedSheet,xPos,yPos,thisClip);
		spriteBox.w = thisClip->w;
		spriteBox.h = thisClip->h;
	}
	spriteBox.x = xPos;             // updates spriteBox on every draw so that spriteBox always moves along 
	spriteBox.y = yPos;             // with the rest of the sprite
}

void Sprite::checkCurrentClip()
{
	if (currentClip / numOfClips >= numOfClips)
	{
		currentClip=0;
	}
}
void Sprite::moveUp()
{
	yPos-=speedY;
	spriteBox.y = yPos;
}

void Sprite::moveDown()
{
	yPos+=speedY;
	spriteBox.y = yPos;
}

void Sprite::moveRight()
{
	xPos+=speedX;
	spriteBox.x = xPos;
}

void Sprite::moveLeft()
{
	xPos-=speedX;
	spriteBox.x = xPos;
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
	spriteBox.x = x;	// set spriteBoxes here in case of sudden Position change
	yPos = y;			
	spriteBox.y = y;
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

int Sprite::getState()
{
	return state;
}

void Sprite::setFacingRight(int n)
{
	facingRight=n;
}

int Sprite::getHalfOfScreen()
{
	return mySDL->getW()/2;
}

int Sprite::getXPos()
{
	return xPos;
}

int Sprite::getFacingRight()
{
	return facingRight;
}

int Sprite::getYPos()
{
	return yPos;
}

int Sprite::getSpeedX()
{
	return speedX;
}

int Sprite::getSpeedY()
{
	return speedY;
}

void Sprite::setSpeed(int xS, int yS)
{
	speedX = xS;
	speedY = yS;
}

void Sprite::incrementCurrentClip()
{
	currentClip++;
}

int Sprite::getCurrentClip()
{
	return currentClip;
}


void Sprite::setMaxSpeed(int n)
{
	maxSpeed=n;
}

void Sprite::incrementSpeed()
{
	if (speedX!=maxSpeed)
	{
		speedX = maxSpeed;
	}
}

void Sprite::setW(int n)
{
	width=n;
}

void Sprite::setH(int n)
{
	height=n;
}
