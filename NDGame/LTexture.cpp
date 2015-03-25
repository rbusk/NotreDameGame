//
//  LTexture.m
//  SDL_Text
//
//  Created by Mary Connolly on 3/13/15.
//  Copyright (c) 2015 Mary. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include "LTexture.h"

LTexture::LTexture()
{
    //Initialize
    mTexture=NULL;
    mWidth=0;
    mHeight=0;
    x=0;
    y=0;
}

LTexture::~LTexture()
{
    free();
}

int LTexture::getX()
{
	return x;
}

int LTexture::getY()
{
	return y;
}

bool LTexture::loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font*& gFont, SDL_Renderer*& gRenderer, int xIn, int yIn)
{
    free();
    
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface==NULL)
    {
        cout << "Unable to render text surface. SDL_ttf error: " << TTF_GetError() << endl;
    }
    
    else
    {
        //create texture from surface pixels
        mTexture=SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture==NULL)
        {
            cout << "Unable to create texture from rendered text. SDL Error: " << SDL_GetError() << endl;
        }
        
        else
        {
            //get image dimensions and set coordinates
            mWidth=textSurface->w;
            mHeight=textSurface->h;
	    x=xIn;
	    y=yIn;
        }
        
        SDL_FreeSurface(textSurface); //get rid of old surface
    }
    
    return mTexture!=NULL;
}

bool LTexture::loadFromFile(string path, SDL_Renderer*& gRenderer)
{
    free();
    
    SDL_Texture* newTexture = NULL; //final texture
    
    //load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        cout << "Unable to load image! Error: " << IMG_GetError();
    }
    
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            cout << "Unable to create texture. SDL Error: " << SDL_GetError();
        }
        
        else // set image dimensions
        {
            mWidth=loadedSurface->w;
            mHeight=loadedSurface->h;
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    
    mTexture=newTexture;
    
    return newTexture!=NULL;
}

void LTexture::free()
{
    if (mTexture!=NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture=NULL;
        mWidth=0;
        mHeight=0;
    }
}

void LTexture::render(SDL_Renderer*& gRenderer)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x,y,mWidth,mHeight};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
