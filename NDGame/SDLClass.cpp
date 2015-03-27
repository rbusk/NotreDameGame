//
//  SDLClass.cpp
//  NotreDameGame
//
//  Created by Mary Connolly on 3/23/15.
//  Copyright (c) 2015 Mary. All rights reserved.
//

#include "SDLClass.h"
#include "LTexture.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

SDLClass :: SDLClass()
{
    w=640;
    h=480;

    init();
}

SDLClass::~SDLClass()
{
    close();
}

int SDLClass::getW()
{
	return w;
}

int SDLClass::getH()
{
	return h;
}

void SDLClass::clear()
{
	SDL_RenderClear(myRenderer);
}

void SDLClass::renderTextures(vector<LTexture*> textures)
{
	for (int i=0; i<textures.size() ; i++)
	{
		textures[i]->render(myRenderer);
	}
}

void SDLClass::update()
{
	SDL_RenderPresent(myRenderer);
}

bool SDLClass::init()
{
    bool success = true;
    
    //Initialize SDL_ttf
    if(TTF_Init()==-1)
    {
        cout << "SDL_ttf could not initialize. SDL_ttf Error: " << TTF_GetError() << endl;
        success=false;
    }
    
    //initialize JPG loading
    int imgFlags=IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize. SDL_image Error: " << IMG_GetError() << endl;
        success= false;
    }
    
    //initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize. Error: " << SDL_GetError();
        success=false;
    }
    
    else
    {
        //Create window
        myWindow = SDL_CreateWindow("Notre Dame Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
        
        if (myWindow == NULL)
        {
            cout << "Window could not be created. Error: " << SDL_GetError();
            success = false;
        }
        
        else
        {
            //create renderer for window
            myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);
            if (myRenderer == NULL)
            {
                cout << "Renderer could not be created. SDL Error: " << SDL_GetError();
            }
            
            else
            {
                //initialize renderer color
                SDL_SetRenderDrawColor(myRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            
        }
    }
    
    return success;

}

bool SDLClass::loadMedia()
{
    
    return 1;
}

LTexture SDLClass::loadFromFile(string path)
{
	LTexture newLTexture; //final LTexture
	SDL_Texture* newTexture=NULL; //final texture

	SDL_Surface* loadedSurface=IMG_Load(path.c_str());

	if(loadedSurface==NULL)
	{
		cout << "Unable to load image! Error: " << IMG_GetError();
	}

	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//create texture from surface pixels
		
		newTexture=SDL_CreateTextureFromSurface(myRenderer, loadedSurface);
		if (newTexture==NULL)
		{
			cout << "Unable to create texture. SDL Error: " << SDL_GetError();
		}

		else //set image dimensions
		{
			newLTexture.setWidth(loadedSurface->w);
			newLTexture.setHeight(loadedSurface->h);
		}

		SDL_FreeSurface(loadedSurface);
	}

	newLTexture.setTexture(newTexture);

	return newLTexture;
}

LTexture SDLClass::loadFromText(string textureText, SDL_Color textColor, TTF_Font *& gFont, int xIn, int yIn)
{
	LTexture newLTexture;
	SDL_Texture *newTexture;

	SDL_Surface* textSurface=TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);

	if (textSurface==NULL)
	{
		cout << "Unable to render text surface. SDL_ttf error: " << TTF_GetError() << endl;
	}

	else
	{
		//create texture from surface pixels
		newTexture=SDL_CreateTextureFromSurface(myRenderer, textSurface);

		if (newTexture==NULL)
		{
			cout << "Unable to create texture from rendered text. SDL Error: " << SDL_GetError() << endl;
		}

		else
		{
			newLTexture.setWidth(textSurface->w);
			newLTexture.setHeight(textSurface->h);
			newLTexture.setX(xIn);
			newLTexture.setY(yIn);
		}

		SDL_FreeSurface(textSurface);
	}

	newLTexture.setTexture(newTexture);

	return newLTexture;
}
	
SDL_Texture* SDLClass::loadTexture(string path)
{
    SDL_Texture* newTexture = NULL; //final texture
    
    //load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        cout << "Unable to load image! Error: " << SDL_GetError();
    }
    
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(myRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            cout << "Unable to create texture. SDL Error: " << SDL_GetError();
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    
    return newTexture;
}

void SDLClass::close()
{
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    myRenderer=NULL;
    myWindow=NULL;
    
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
