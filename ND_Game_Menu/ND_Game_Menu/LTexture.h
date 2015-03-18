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
    ~LTexture(); //deallocates memory
    bool loadFromFile(string path); //load image
    bool loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font*& gFont, SDL_Renderer*& gRenderer);
    void free(); //deallocate texture
    void render(int x, int y, SDL_Renderer *& gRenderer); //renders texture at given point
    int getWidth(); //gets image dimensions
    int getHeight();
    
private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
};


#endif