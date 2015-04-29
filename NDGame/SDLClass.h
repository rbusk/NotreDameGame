//SDL wrapper

#ifndef SDLCLASS_H
#define SDLCLASS_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "LTexture.h"
#include <vector>
#include <SDL2/SDL_mixer.h>

class SDLClass {
    
public:
    SDLClass(); //constructor
    ~SDLClass(); //destructor
    bool init(); //initialize
    void close(); //close
    SDL_Texture* loadTexture(string path); //load a texture from a path
    void clear(); //clear
    void renderTextures(vector<LTexture>); //render textures
    void renderSprite(LTexture, int, int, SDL_Rect* clip); //render sprite by rendering one of its clips
    void update(); //update
    int getW(); //return width
    int getH(); //return height
    LTexture loadFromFile(string path); //create LTexture from path
    LTexture loadFromText(string textureText, SDL_Color textColor, TTF_Font *& gFont, int xIn, int yIn); //create LTexture from text
    
private:
    SDL_Window *myWindow; //pointer to SDL_Window
    SDL_Renderer *myRenderer; //pointer to SDL_Renderer
    vector <LTexture*> textures; //vector of textures
    int h; //height of screen
    int w; //width of screen
    
};

#endif
