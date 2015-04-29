//derived from Static Screen and used for side scroller game

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "StaticScreen.h"
#include "FootballPowerup.h"
#include <string>
using namespace std;

class Background : public StaticScreen {

	public:

		Background(SDLClass &myC);
		void displayGameOver(int); //display the words "game over" (or not)
                void displayLevel(int); //display level in corner of screen

	private:
		FootballPowerup *football; //image of football which indicates if player has a football or not

		
};
#endif
