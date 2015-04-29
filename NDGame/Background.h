#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "StaticScreen.h"
#include "FootballPowerup.h"

class Background : public StaticScreen {

	public:

		Background(SDLClass &myC);
		void displayGameOver(int); //display the words "game over" (or not)
                void displayLevel(int);

	private:
		FootballPowerup *football;

		
};
#endif
