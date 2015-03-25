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
        int screenState = 0;
	    LTexture bg, text1, text2, bg2, endText; //background
        
        // Opening Screen (screenState 0)
	    bg.loadFromFile("resources/dome2.jpg", mySDL.myRenderer);

	    TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);

	    SDL_Color textColor={255, 255, 255};

	    text1.loadFromRenderedText("Really awesome game", textColor, font, mySDL.myRenderer, mySDL.getW()/30, mySDL.getH()/8);

	    font=TTF_OpenFont("resources/OpenSans-Regular.ttf", 14);
	    text2.loadFromRenderedText("Press any key to continue", textColor, font, mySDL.myRenderer, mySDL.getW()/30, mySDL.getH()/4);

	    textures.push_back(&bg);
	    textures.push_back(&text1);
	    textures.push_back(&text2);
        
        // screenState 1
        bg2.loadFromFile("resources/diploma.jpg", mySDL.myRenderer);
        
        font = TTF_OpenFont("resources/OpenSans-Bold.ttf", 20);
        SDL_Color endTextColor={0,0,0};
        
        endText.loadFromRenderedText("YOU GRADUATED!", endTextColor, font, mySDL.myRenderer, mySDL.getW()/2, mySDL.getH()/20);
        
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
                    screenState++;
			    }
		    }

            switch (screenState) {
                case 0:
                    break;
                case 1:
                    textures.clear();
                    textures.push_back(&bg2);
                    textures.push_back(&endText);
                    break;
                default:
                    quit=true;
            }
            
		    mySDL.clear();
		    mySDL.renderTextures(textures);
		    mySDL.update();
	    }
	    
	    mySDL.close();
    }
    
    return 0;
}
