/* Sprite Generator that generates sprites randomly */

#ifndef SPRITEGENERATOR_H
#define SPRITEGENERATOR_H

#include <vector>
#include "SDLClass.h"
#include "Timer.h"
#include "Sprite.h"
#include "Player.h"
#include "Hotdog.h"
#include "Hamburger.h"
#include "Car1.h"
#include "Car2.h"
#include "Footballer.h"

enum SpriteType {
	isCar1,
	isCar2,
	isFootballer,
	isHotdog,
	isHamburger
};

class SpriteGenerator {

	public:
		SpriteGenerator(SDLClass &myC);
		~SpriteGenerator();
		void setFrequency(int,int);					// how many on screen at same time

		void setSprites(vector<SpriteType>); 	// send in enemies you wish to generate
		void generateSprites(Player*); 	// creates new sprites and puts them in private vector
		void packageSprites(vector<Sprite*>&);	// will add generated sprites to enemies vector

		void destroyPastSprites(Player*, vector<Sprite*>&);	// dynamically delete past enemies

	private:
		vector<SpriteType> spritesToBe;
		vector<Sprite*> createdSprites;

		Timer spawnTimer;
		int freqLower;
		int freqHigher;
		int screenW;
		int screenH;
		SDLClass *mySDL;
		
};

#endif