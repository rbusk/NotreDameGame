//implementation for LTexture

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "LTexture.h"

LTexture::LTexture() //constructor
{
    //Initialize
    mTexture=NULL;
    mWidth=0;
    mHeight=0;
    x=0;
    y=0;
    draw=1;
}

int LTexture::getX() //return x
{
	return x;
}

int LTexture::getY() //return y
{
	return y;
}

void LTexture::setX(int n) //set x
{
	x=n;
}

void LTexture::setY(int n) //set y
{
	y=n;
}

//load from text
bool LTexture::loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font*& gFont, SDL_Renderer*& gRenderer, int xIn, int yIn)
{
    free();
    
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface==NULL) //display error message if need be
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
    
    return mTexture!=NULL; //return bool to indicate if successful
}

//load from image
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
    
    return newTexture!=NULL; //return bool to indicate if successful
}

//free texture by destroying texture, setting pointer to null, etc
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

//render texture
void LTexture::render(SDL_Renderer*& gRenderer)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x,y,mWidth,mHeight};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

//render a clip for a sprite
void LTexture::renderClip(SDL_Renderer*& gRenderer, int xc, int yc, SDL_Rect* clip)
{
    SDL_Rect renderQuad = { xc, yc, mWidth, mHeight };

    // set clip rendering dimensions
    if (clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int LTexture::getWidth() //return width
{
    return mWidth;
}

int LTexture::getHeight() //return height
{
    return mHeight;
}

void LTexture::setWidth(int w)
{
	mWidth=w;
}

void LTexture::setHeight(int h)
{
	mHeight=h;
}

void LTexture::setTexture(SDL_Texture* t)
{
	mTexture=t;
}

void LTexture::setDraw(int n)
{
	draw=n;
}

int LTexture::getDraw()
{
	return draw;
}
