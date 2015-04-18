/* implementation file for StaticScreen class */

#include "StaticScreen.h"

//constructor assigns pointer to SDLClass
StaticScreen::StaticScreen(SDLClass &myC)
{
	mySDL=&myC;
	setIsScrolling(isNotScrolling);
}

//destructor calls function destroyScreen
StaticScreen::~StaticScreen()
{
	destroyScreen();
}

//destroy Screen frees the textures in the vector
void StaticScreen::destroyScreen()
{
	for (int i; i<textures.size(); i++)
	{
		textures[i].free();
	}

}

//update screen
void StaticScreen::draw()
{	
	if (isScrollingScreen)
	{
		if (isScrolling)
		{
			//scrollingOffset-=speed;
			scrollingOffset-=speed;
		}

		if (scrollingOffset < -textures[0].getWidth())
		{
			scrollingOffset=0;
		}

		mySDL->clear();
		textures[0].setX(scrollingOffset);
		mySDL->renderTextures(textures);
		textures[0].setX(scrollingOffset + textures[0].getWidth());
		mySDL->renderTextures(textures);
	}

	else
	{
		mySDL->clear();
		mySDL->renderTextures(textures);
	}	
}

//load new texture and add it to textures
void StaticScreen::loadFromFile(string path)
{
	LTexture newTexture;
	newTexture=mySDL->loadFromFile(path); //load new texture
	textures.push_back(newTexture); //add to vector of textures
}

void StaticScreen::loadFromText(string textureText, SDL_Color textColor, TTF_Font*& gFont, int xIn, int yIn)
{
	LTexture newTexture;
	newTexture=mySDL->loadFromText(textureText, textColor, gFont, xIn, yIn);
	textures.push_back(newTexture);
}

int StaticScreen::getSize()
{
	return textures.size();
}

SDLClass * StaticScreen::getSDL()
{
	return mySDL;
}

void StaticScreen::setIsScrolling(int x)
{
	isScrolling=x;
}

void StaticScreen::setIsScrollingScreen(int x)
{
	isScrollingScreen=x;
}

int StaticScreen::getIsScrolling() 
{
	return isScrolling;
}

void StaticScreen::setSpeed(int n)
{
	speed=n;
}

void StaticScreen::incrementSpeed(int n)
{
	speed+=n;
}

void StaticScreen::setScrollingOffset(int n)
{
	scrollingOffset=n;
}

LTexture* StaticScreen::getTexture(int n)
{
	return &textures[n];
}

void StaticScreen::displayGameOver()
{
}
