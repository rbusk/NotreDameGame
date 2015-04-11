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
	facingRight=1;
	mySDL=&myC;
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
}

void Sprite::draw()
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
	}

	//if sprite is facing left
	else
	{
		SDL_Rect* thisClip = &flippedClips[currentClip/numOfClips];
		mySDL->renderSprite(flippedSheet,xPos,yPos,thisClip);
	}
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
}

void Sprite::moveDown()
{
	yPos+=speedY;
}

void Sprite::moveRight()
{
	xPos+=speedX;
}

void Sprite::moveLeft()
{
	xPos-=speedX;
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

void Sprite::setIsLoaded(bool l)
{
	isLoaded = l;
}

bool Sprite::getIsLoaded() 
{
	return isLoaded;
}
