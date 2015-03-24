//
//  SDLClass.h
//  NotreDameGame
//
//  Created by Mary Connolly on 3/23/15.
//  Copyright (c) 2015 Mary. All rights reserved.
//

#ifndef __NotreDameGame__SDLClass__
#define __NotreDameGame__SDLClass__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
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
    void renderTextures(vector<LTexture*>);
    void update();
    SDL_Renderer* getRenderer();
    int getW();
    int getH();
    SDL_Renderer *myRenderer;
    
private:
    SDL_Window *myWindow;
    //SDL_Renderer *myRenderer;
    vector <LTexture*> textures;
    int h;
    int w;
    
};


#endif /* defined(__NotreDameGame__SDLClass__) */
