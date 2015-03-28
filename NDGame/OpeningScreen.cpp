#include "OpeningScreen.h"
#include "StaticScreen.h"

OpeningScreen::OpeningScreen(SDLClass &myC) 
: StaticScreen(myC)
{
	loadFromFile("resources/dome2.jpg");

	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);
	SDL_Color textColor={255, 255, 255};

	loadFromText("Really awesome game", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8);

	font=TTF_OpenFont("resources/OpenSans-Regular.ttf", 14);

	loadFromText("Press any key to continue", textColor, font, getSDL()->getW()/30, getSDL()->getH()/4);
}
