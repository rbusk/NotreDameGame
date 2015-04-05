//
//  SDLClass.h
//  NotreDameGame
//
//  Created by Mary Connolly on 3/23/15.
//  Copyright (c) 2015 Mary. All rights reserved.
//

#ifndef SDLCLASS_H
#define SDLCLASS_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "LTexture.h"
#include <vector>

class SDLClass {
    
public:
    SDLClass();
    ~SDLClass();
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture(string path);
    void clear();
    void renderTextures(vector<LTexture>);
    void renderSprite(LTexture, int, int, SDL_Rect* clip);
    void update();
    int getW();
    int getH();
    LTexture loadFromFile(string path);
    LTexture loadFromText(string textureText, SDL_Color textColor, TTF_Font *& gFont, int xIn, int yIn);
    
private:
    SDL_Window *myWindow;
    SDL_Renderer *myRenderer;
    vector <LTexture*> textures;
    int h;
    int w;
    
};

#endif
