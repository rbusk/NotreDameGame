#include "OpeningScreen.h"
#include "StaticScreen.h"

OpeningScreen::OpeningScreen(SDLClass &myC) 
: StaticScreen(myC)
{
	setIsScrolling(0);

	loadFromFile("resources/dome2.png");

	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);
//	SDL_Color textColor={255, 255, 255};
	SDL_Color textColor={0,0,0};
	loadFromText("ND Tailgate", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8);

	font=TTF_OpenFont("resources/OpenSans-Regular.ttf", 14);

	loadFromText("It's football Saturday at Notre Dame", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+100);
	loadFromText("and you need to get past the crowds to study.", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+120);
	loadFromText("Grab footballs and food.", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+140);
	loadFromText("Avoid everything else. Especially the demon squirrels.", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+160);
	loadFromText("Injure football players by throwing a football.", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+180);
	loadFromText("A,D -> move", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+220);
	loadFromText("W -> jump", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+240);
	loadFromText("space -> throw football", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+260);

	loadFromText("Press any key to continue", textColor, font, getSDL()->getW()/30, getSDL()->getH()/8+300);
}
