/* implementation file for Sprite class */

#include "Sprite.h"
#include "box.h"
#include <vector>

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
	spriteBox.init(xPos,yPos,height, width);
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
	spriteBox.setY(yPos);
}

void Sprite::moveDown()
{
	yPos+=speedY;
	spriteBox.setY(yPos);
}

void Sprite::moveRight()
{
	xPos+=speedX;
	spriteBox.setX(xPos);
}

void Sprite::moveLeft()
{
	xPos-=speedX;
	spriteBox.setX(xPos);
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

void Sprite::collisionLoop(vector<Sprite*> enemyVector)
{
	int check = 0;

	for(int i = 0; i < enemyVector.size(); i++)
	{
		//add is loaded if statement
		check = collision(enemyVector[i]);

		if (check == 1)
		{
			if(enemyVector[i]->getXPos() > xPos)
			{
				moveLeft();
			}
			else
			{
				moveRight();
			}
			
		}
	}
}

int Sprite::collision(Sprite* enemy)
{
	vector<int> leftPlayer, leftEnemy;
	vector<int> rightPlayer, rightEnemy;
	vector<int> topPlayer, topEnemy;
	vector<int> bottomPlayer, bottomEnemy;

	leftPlayer = spriteBox.getTopLeft();
	rightPlayer = spriteBox.getTopRight();
	topPlayer = spriteBox.getTopLeft();
	bottomPlayer = spriteBox.getBottomRight();

	leftEnemy = enemy->spriteBox.getTopLeft();
	rightEnemy = enemy->spriteBox.getTopRight();
	topEnemy = enemy->spriteBox.getTopLeft();
	bottomEnemy = enemy->spriteBox.getBottomRight();

	if (bottomPlayer[2] <= topEnemy[2])
	{
		return false;
	}

	if (topPlayer[2] >= bottomEnemy[2])
	{
		return false;
	}
	
	if (rightPlayer[1] <= leftEnemy[1])
	{
		return false;
	}

	if (leftPlayer[1] >= rightEnemy[1])
	{
		return false;
	}

	return true;
}

void Sprite::setIsLoaded(bool l)
{
	isLoaded = l;
}

bool Sprite::getIsLoaded() 
{
	return isLoaded;
}
