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
}

LTexture::~LTexture()
{
    free();
}

bool LTexture::loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font*& gFont, SDL_Renderer*& gRenderer)
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
            //get image dimensions
            mWidth=textSurface->w;
            mHeight=textSurface->h;
        }
        
        SDL_FreeSurface(textSurface); //get rid of old surface
    }
    
    return mTexture!=NULL;
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

void LTexture::render(int x, int y, SDL_Renderer*& gRenderer)
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