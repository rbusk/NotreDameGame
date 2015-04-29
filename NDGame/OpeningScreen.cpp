#include "OpeningScreen.h"
#include "StaticScreen.h"

OpeningScreen::OpeningScreen(SDLClass &myC) 
: StaticScreen(myC)
{
	setIsScrolling(0);

	loadFromFile("resources/dome2.png");

	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);
	SDL_Color textColor={255, 255, 255};

	loadFromText("ND Tailgate", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8);

	font=TTF_OpenFont("resources/OpenSans-Regular.ttf", 14);

	loadFromText("Press any key to continue", textColor, font, getSDL()->getW()/30, getSDL()->getH()/4);
}
