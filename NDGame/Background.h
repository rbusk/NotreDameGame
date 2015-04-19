#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "StaticScreen.h"
#include "FootballPowerup.h"

class Background : public StaticScreen {

	public:

		Background(SDLClass &myC);
		void displayGameOver(); //display the words "game over"

	private:
		FootballPowerup *football;

		
};
#endif
