#include "Background.h"
#include "StaticScreen.h"
#include "FootballPowerup.h"

Background::Background(SDLClass &myC)
	: StaticScreen(myC)
{
	loadFromFile("resources/bg2.png");
	setIsScrollingScreen(1);
	setSpeed(2);

	TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 40);
	SDL_Color textColor={0,0,0};

	loadFromText("Game Over", textColor, font, getSDL()->getW()/3, getSDL()->getH()/8);

	getTexture(1)->setDraw(0);

	loadFromFile("resources/football.png"); //for football in corner indicating if player has a football

	getTexture(2)->setDraw(0);

        loadFromText("Level: ", textColor, font, getSDL()->getW()/20, getSDL()->getH()/20);

        getTexture(3)->setDraw(0);
}	

void Background::displayGameOver(int n)
{
	if (n==1)
	{
		//set draw of texture 1 (words displaying "game over") to 1 if n==1
		getTexture(1)->setDraw(1);
	}

	else
	{
		//else set draw of texture 1 to 0
		getTexture(1)->setDraw(0);
	}
}

void Background::displayLevel(int lvl)
{
        TTF_Font *font=TTF_OpenFont("resources/OpenSans-Bold.ttf", 30);
        SDL_Color textColor={0,0,0};

        LTexture level;     
        string l = "Level: " + to_string(lvl);
        level = getSDL()->loadFromText(l, textColor, font, getSDL()->getW()-getSDL()->getW()/5, getSDL()->getH()/40);
        setTexture(level,3);
        getTexture(3)->setDraw(1);
}
