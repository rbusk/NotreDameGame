//
//  main.cpp
//  ND_Game_Menu
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
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool loadMedia();
SDL_Texture* loadTexture(string path);
void close();
bool init();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
TTF_Font *gFont = NULL;
LTexture gTextTexture;
LTexture gTextTexture2;
SDL_Texture* picTexture;

int main(int argc, const char * argv[]) {
    
    //Start up SDL and create window
    if (!init())
    {
        cout << "Failed to initialize." << endl;
    }
    
    else
    {
        //Load media
        if (!loadMedia())
        {
            cout << "Failed to load media." << endl;
        }
        
        else
        {
            bool quit = false; //keeps track of whether user has quit or not
            
            SDL_Event e; //event handler
            
            while (!quit)
            {
                while (SDL_PollEvent(&e) !=0)
                {
                    if (e.type==SDL_QUIT)
                    {
                        quit=true;
                    }
                    
                    else if (e.type == SDL_KEYDOWN) //user presses a key
                    {
                        quit=true;
                    }
                }
                
                //clear screen
                SDL_RenderClear(gRenderer);
                
                //render current frame
                SDL_RenderCopy(gRenderer, picTexture, NULL, NULL);
                gTextTexture.render(SCREEN_WIDTH/30, SCREEN_WIDTH/8, gRenderer);
                gTextTexture2.render(SCREEN_WIDTH/30, SCREEN_WIDTH/4, gRenderer);
                SDL_RenderPresent(gRenderer);
            }
        }
    }
    
    return 0;
}

bool loadMedia()
{
    bool success=true;
    
    //load dome pic
    picTexture = loadTexture("dome2.jpg");
    if (picTexture == NULL)
    {
        cout << "Failed to load dome pic." << endl;
        success= false;
    }
    
    //Open the font
    gFont=TTF_OpenFont("OpenSans-Bold.ttf", 40);
    
    if (gFont==NULL)
    {
        cout << "Failed to open font. SDL_ttf error: " << TTF_GetError() << endl;
        success=false;
    }
    
    else //render text
    {
        SDL_Color textColor={255, 255, 255};
        
        if (!gTextTexture.loadFromRenderedText("Really awesome game", textColor, gFont, gRenderer))
        {
            cout << "Failed to render text texture 1" << endl;
            success=false;
        }
    }
    
    //Open new font
    gFont=TTF_OpenFont("OpenSans-Regular.ttf", 14);
    
    if (gFont==NULL)
    {
        cout << "Failed to open font. SDL_ttf error: " << TTF_GetError() << endl;
        success=false;
    }
    
    else //render text
    {
        SDL_Color textColor={255, 255, 255};
        
        if (!gTextTexture2.loadFromRenderedText("Press any key to continue.", textColor, gFont, gRenderer))
        {
            cout << "Failed to render text texture 2" << endl;
            success=false;
        }
    }
    
    return success;
}

SDL_Texture* loadTexture(string path)
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
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            cout << "Unable to create texture. SDL Error: " << SDL_GetError();
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    
    return newTexture;
}

bool init()
{
    bool success = true;
    
    //Initialize SDL_ttf
    if(TTF_Init()==-1)
    {
        cout << "SDL_ttf could not initialize. SDL_ttf Error: " << TTF_GetError() << endl;
        success=false;
    }
    
    //initialize PNG loading
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
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        
        if (gWindow == NULL)
        {
            cout << "Window could not be created. Error: " << SDL_GetError();
            success = false;
        }
        
        else
        {
            //create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                cout << "Renderer could not be created. SDL Error: " << SDL_GetError();
            }
            
            else
            {
                //initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            
        }
    }
    
    return success;
}

void close()
{
    gTextTexture.free(); //free loaded image
    gTextTexture2.free();
    
    SDL_DestroyTexture(picTexture);
    picTexture=NULL;
    
    //free global font
    TTF_CloseFont(gFont);
    gFont=NULL;
    
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gRenderer=NULL;
    gWindow=NULL;
    
    SDL_Quit();
    TTF_Quit();
}