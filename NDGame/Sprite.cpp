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
	//spriteBox.x = xPos;
	//spriteBox.y = yPos;
	//spriteBox.h = height;
	//spriteBox.w = width;
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
	//spriteBox.setY(yPos);
	spriteBox.y = yPos;
}

void Sprite::moveDown()
{
	yPos+=speedY;
	//spriteBox.setY(yPos);
	spriteBox.y = yPos;
}

void Sprite::moveRight()
{
	xPos+=speedX;
	//spriteBox.setX(xPos);
	spriteBox.x = xPos;
}

void Sprite::moveLeft()
{
	xPos-=speedX;
	//spriteBox.setX(xPos);
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

/*void Sprite::collisionLoop(vector<Sprite*> enemyVector)
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
	vector<int> leftTopCornerP, leftTopCornerE;
	vector<int> rightBottomCornerP, rightBottomCornerE;

	leftTopCornerP = spriteBox.getTopLeft();
	rightBottomCornerP = spriteBox.getBottomRight();

	leftTopCornerE = enemy->spriteBox.getTopLeft();
	rightBottomCornerE = enemy->spriteBox.getBottomRight();

	if (rightBottomCornerP[2] <= leftTopCornerE[2])
	{
		return false;
	}

	if (leftTopCornerP[2] >= rightBottomCornerE[2])
	{
		return false;
	}
	
	if (rightBottomCornerP[1] <= leftTopCornerE[1])
	{
		return false;
	}

	if (leftTopCornerP[1] >= rightBottomCornerE[1])
	{
		return false;
	}

	return true;
}*/

void Sprite::setIsLoaded(bool l)
{
	isLoaded = l;
}

bool Sprite::getIsLoaded() 
{
	return isLoaded;
}

/*void Sprite::collisionLoopRect(vector<Sprite*> enemyVector)
{
	int check = 0;

	Sprite* ptr; //use to determine what kind of sprite

	for(int i = 0; i < enemyVector.size(); i++)
	{
		check = 0;
		//add is loaded if statement
		check = collisionCheck(enemyVector[i]);

		if (check==1)
		{
			if (typeid(*ptr)==typeid(Hotdog))
			{
				cout << "collided with hotdog. yum" << endl;
			}

			else if (typeid(*ptr)==typeid(Car1))
			{
				cout << "collided with car. vroom" << endl;
			}
		}


		if (check == 1 && xPos > enemyVector[i]->getXPos())
		{
			cout << "Colliding Left" << endl;
		}
		if (check == 1 && xPos < enemyVector[i]->getXPos())
		{
			cout << "Colliding Right" << endl;
		}
		if (check == 1 && yPos+height == enemyVector[i]->getYPos())
		{
			cout << "On Top" << endl;
		}
		if (check == 0)
			cout << "Not Colliding" << endl;
	}
}

int Sprite::collisionCheck(Sprite* enemy)
{
	SDL_bool value;
	SDL_Rect enemyRect;

	enemyRect.x = enemy->spriteBox.x;
	enemyRect.y = enemy->spriteBox.y;
	enemyRect.h = enemy->spriteBox.h;
	enemyRect.w = enemy->spriteBox.w;

	value = SDL_HasIntersection(&spriteBox,&enemyRect);

	if (value == SDL_TRUE)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}*/

void Sprite::incrementSpeed()
{
	speedX = speedX + speedIncrement;
}

void Sprite::setSpeedIncrement(int n)
{
	speedIncrement=n;
}
