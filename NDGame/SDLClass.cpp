//implementation for SDL wrapper
#include "SDLClass.h"
#include "LTexture.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

SDLClass :: SDLClass() //constructor
{
//set height and width of screen
    w=640;
    h=480;

    init(); //initialize
}

SDLClass::~SDLClass() //destructor
{
    close();
}

int SDLClass::getW() //return width of screen
{
	return w;
}

int SDLClass::getH() //return height of screen
{
	return h;
}

void SDLClass::clear() //clear renderer
{
	SDL_RenderClear(myRenderer);
}

void SDLClass::renderTextures(vector<LTexture> textures) //render textures
{
	for (int i=0; i<textures.size() ; i++)
	{
		//only render if draw==1
		if (textures[i].getDraw())
		{
			textures[i].render(myRenderer);
		}
	}
}

//render a sprite by rendering one of its clips
void SDLClass::renderSprite(LTexture texture, int x, int y, SDL_Rect* clip)
{
    texture.renderClip(myRenderer,x,y,clip);
}

//update renderer
void SDLClass::update()
{
	SDL_RenderPresent(myRenderer);
}

//initialize
bool SDLClass::init()
{
    bool success = true; //indicates if initialization was a success
    
    //Initialize SDL_ttf
    if(TTF_Init()==-1)
    {
        cout << "SDL_ttf could not initialize. SDL_ttf Error: " << TTF_GetError() << endl;
        success=false;
    }
    
    //initialize PNG loading
    int imgFlags=IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize. SDL_image Error: " << IMG_GetError() << endl;
        success= false;
    }
    
    //initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cout << "SDL could not initialize. Error: " << SDL_GetError();
        success=false;
    }
    
    else
    {
        //Create window
        myWindow = SDL_CreateWindow("Notre Dame Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
        
        if (myWindow == NULL) //if window not created correctly, display error message
        {
            cout << "Window could not be created. Error: " << SDL_GetError();
            success = false;
        }
        
        else
        {
            //create renderer for window
            myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (myRenderer == NULL) //if renderer not created correctly, display error message
            {
                cout << "Renderer could not be created. SDL Error: " << SDL_GetError();
            }
            
            else
            {
                //initialize renderer color
                SDL_SetRenderDrawColor(myRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            
        }
    }

    //Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
    {
	    cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
	    success = false;
    }
    
    return success;

}

//return LTexture by creating from file
LTexture SDLClass::loadFromFile(string path)
{
	LTexture newLTexture; //final LTexture
	SDL_Texture* newTexture=NULL; //final texture

	SDL_Surface* loadedSurface=IMG_Load(path.c_str());

	if(loadedSurface==NULL) //print error if not loaded correctly
	{
		cout << "Unable to load image! Error: " << IMG_GetError();
	}

	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//create texture from surface pixels
		
		newTexture=SDL_CreateTextureFromSurface(myRenderer, loadedSurface);
		if (newTexture==NULL)
		{
			cout << "Unable to create texture. SDL Error: " << SDL_GetError();
		}

		else //set image dimensions
		{
			newLTexture.setWidth(loadedSurface->w);
			newLTexture.setHeight(loadedSurface->h);
		}

		SDL_FreeSurface(loadedSurface);
	}

	newLTexture.setTexture(newTexture);

	return newLTexture; //return new LTexture
}

//create new LTexture from text
LTexture SDLClass::loadFromText(string textureText, SDL_Color textColor, TTF_Font *& gFont, int xIn, int yIn)
{
	LTexture newLTexture; //final LTexture
	SDL_Texture *newTexture;

	SDL_Surface* textSurface=TTF_RenderText_Solid(gFont, textureText.c_str(), textColor); //create surface from text

	if (textSurface==NULL)
	{
		cout << "Unable to render text surface. SDL_ttf error: " << TTF_GetError() << endl;
	}

	else
	{
		//create texture from surface pixels
		newTexture=SDL_CreateTextureFromSurface(myRenderer, textSurface);

		if (newTexture==NULL)
		{
			cout << "Unable to create texture from rendered text. SDL Error: " << SDL_GetError() << endl;
		}

		else
		{
			//set x, y, width, and height of LTexture
			newLTexture.setWidth(textSurface->w);
			newLTexture.setHeight(textSurface->h);
			newLTexture.setX(xIn);
			newLTexture.setY(yIn);
		}

		SDL_FreeSurface(textSurface);
	}

	newLTexture.setTexture(newTexture);

	return newLTexture; //return new texture
}
	
//return pointer to SDL_Texture by creating one using a path
SDL_Texture* SDLClass::loadTexture(string path)
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
        newTexture = SDL_CreateTextureFromSurface(myRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            cout << "Unable to create texture. SDL Error: " << SDL_GetError();
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    
    return newTexture;
}

//close - call in destructor
void SDLClass::close()
{
    SDL_DestroyWindow(myWindow);
    SDL_DestroyRenderer(myRenderer);
    myRenderer=NULL;
    myWindow=NULL;
    
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
