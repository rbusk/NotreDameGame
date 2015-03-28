/* implementation file for StaticScreen class */

#include "StaticScreen.h"

//constructor assigns pointer to SDLClass
StaticScreen::StaticScreen(SDLClass &myC)
{
	mySDL=&myC;
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
	mySDL->clear();
	mySDL->renderTextures(textures);
	mySDL->update();
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
