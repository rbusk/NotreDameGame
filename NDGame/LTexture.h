//
//  LTexture.h
//  SDL_Text
//
//  Created by Mary Connolly on 3/13/15.
//  Copyright (c) 2015 Mary. All rights reserved.
//

#include <iostream>
using namespace std;

#ifndef LTexture_h
#define LTexture_h

class LTexture
{
public:
    LTexture(); //initializes variables
    bool loadFromFile(string path, SDL_Renderer*& gRenderer); //load image
    bool loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font*& gFont, SDL_Renderer*& gRenderer, int xIn, int yIn); //load text
    void free(); //deallocate texture
    void render(SDL_Renderer *& gRenderer); //renders texture at given point
    void renderClip(SDL_Renderer *& gRenderer, int, int, SDL_Rect* clip); //render clip from texture
    int getWidth(); //gets image dimensions
    int getHeight(); //return height
    void setWidth(int w);
    void setHeight(int h);
    void setTexture(SDL_Texture* t);
    int getX(); //get x position
    int getY(); //get y position
    void setX(int n); //set x position
    void setY(int n); //set y position
    void setDraw(int n); //set whether or not to draw LTexture
    int getDraw(void);
    
private:
    SDL_Texture* mTexture; //pointer to texture
    int mWidth; //width of LTexture
    int mHeight; //height of LTexture
    int x; //x position
    int y; //y position
    int draw; //1 if draw, otherwise 0
};


#endif
