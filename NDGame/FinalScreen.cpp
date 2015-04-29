#include "FinalScreen.h"
#include "StaticScreen.h"

FinalScreen::FinalScreen(SDLClass &myC) 
: StaticScreen(myC)
{
	setIsScrolling(0);
	setIsScrollingScreen(0);

	loadFromFile("resources/library.jpg");

	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);
	SDL_Color textColor={255, 255, 255};

	loadFromText("You win!", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8);

	font=TTF_OpenFont("resources/OpenSans-Regular.ttf", 14);

	loadFromText("Study well young grasshopper.", textColor, font, getSDL()->getW()/30, getSDL()->getH()/4);

	loadFromText("Press space to restart", textColor, font, getSDL()->getW()/30, getSDL()->getH()/3);
}
