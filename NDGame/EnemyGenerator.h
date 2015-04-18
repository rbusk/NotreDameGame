/* Sprite Generator that generates enemies randomly */

#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include <vector>
#include "SDLClass.h"
#include "Sprite.h"
#include "Hotdog.h"
#include "Hamburger.h"
#include "Car1.h"
#include "Car2.h"
#include "Footballer.h"

enum EnemyType {
	isHotdog,
	isHamburger,
	isCar1,
	isCar2,
	isFootballer
};

class EnemyGenerator {

	public:
		EnemyGenerator(SDLClass &myC);
		~EnemyGenerator();
		void setFrequency(int);					// how many on screen at same time

		void setEnemies(vector<EnemyType>); 	// send in enemies you wish to generate
		Sprite* generateSprites(); 				// creates new sprites and puts them in private vector
		void packageSprites(vector<Sprite*>&);	// will add generated sprites to enemies vector

	private:
		vector<EnemyType> spritesToBe;
		vector<Sprite*> createdSprites;
		int frequency;
		int screenW;
		int screenH;
		SDLClass *mySDL;
		
};