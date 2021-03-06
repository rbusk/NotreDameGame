#include "GraduatingScreen.h"
#include "StaticScreen.h"

GraduatingScreen::GraduatingScreen(SDLClass &myC)
	: StaticScreen(myC)
{
	setIsScrollingScreen(0);

	loadFromFile("resources/diploma.png");
	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 20);
	SDL_Color textColor={0,0,0};

	loadFromText("YOU GRADUATED!", textColor, font, getSDL()->getW()/2.8, getSDL()->getH()/25);
}
