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
    bool loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font*& gFont, SDL_Renderer*& gRenderer, int xIn, int yIn);
    void free(); //deallocate texture
    void render(SDL_Renderer *& gRenderer); //renders texture at given point
    void renderClip(SDL_Renderer *& gRenderer, int, int, SDL_Rect* clip); //render clip from texture
    int getWidth(); //gets image dimensions
    int getHeight();
    void setWidth(int w);
    void setHeight(int h);
    void setTexture(SDL_Texture* t);
    int getX();
    int getY();
    void setX(int n);
    void setY(int n);
    void setDraw(int n);
    int getDraw(void);
    
private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
    int x; //x position
    int y; //y position
    int draw; //1 if draw, otherwise 0
};


#endif
