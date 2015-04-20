#include "Background.h"
#include "StaticScreen.h"
#include "FootballPowerup.h"

Background::Background(SDLClass &myC)
	: StaticScreen(myC)
{
	loadFromFile("resources/bg.png");
	setIsScrollingScreen(1);
	setSpeed(2);

	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);
	SDL_Color textColor={0,0,0};

	loadFromText("Game Over", textColor, font, getSDL()->getW()/3, getSDL()->getH()/8);

	getTexture(1)->setDraw(0);

	loadFromFile("resources/football.png"); //for football in corner indicating if player has a football

	getTexture(2)->setDraw(0);
}	

void Background::displayGameOver()
{
	//set draw of texture 1 (words displaying "game over") to 1
	getTexture(1)->setDraw(1);
}
