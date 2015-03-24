#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <vector>
#include "LTexture.h"
#include "SDLClass.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    SDLClass mySDL;

    vector<LTexture*> textures;
    
    if (!mySDL.init())
    {
        cout << "Failed to initialize." << endl;
    }

    else
    {
	    LTexture bg, text1, text2; //background

	    bg.loadFromFile("dome2.jpg", mySDL.myRenderer);

	    TTF_Font *font=TTF_OpenFont("OpenSans-Bold.ttf", 40);

	    SDL_Color textColor={255, 255, 255};

	    text1.loadFromRenderedText("Really awesome game", textColor, font, mySDL.myRenderer, mySDL.getW()/30, mySDL.getH()/8);

	    font=TTF_OpenFont("OpenSans-Regular.ttf", 14);
	    text2.loadFromRenderedText("Press any key to continue", textColor, font, mySDL.myRenderer, mySDL.getW()/30, mySDL.getH()/4);

	    textures.push_back(&bg);
	    textures.push_back(&text1);
	    textures.push_back(&text2);

	    bool quit=false;

	    SDL_Event e; //event handler

	    while (!quit)
	    {
		    while (SDL_PollEvent(&e) != 0)
		    {
			    if (e.type==SDL_QUIT)
			    {
				    quit=true;
			    }

			    else if (e.type==SDL_KEYDOWN) //user presses a key
			    {
				    quit=true;
			    }
		    }

		    mySDL.clear();
		    mySDL.renderTextures(textures);
		    mySDL.update();
	    }
	    
	    mySDL.close();
    }
    
    return 0;
}
