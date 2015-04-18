#include "EnemyGenerator.h"
#include "SDLClass.h"
#include <stdlib.h>

EnemyGenerator::EnemyGenerator(SDLClass &myC) 
{
	mySDL = &myC;
	screenW = mySDL->getW();
	screenH = mySDL->getH();
	frequency = 0;
	srand(time(NULL));
}

EnemyGenerator::~EnemyGenerator() 
{

}

void EnemyGenerator::setFrequency(int f)
{
	frequency = f;
}

void EnemyGenerator::setEnemies(vector<enemyType> desired)
{
	spritesToBe = desired;
}

Sprite* EnemyGenerator::generateSprites() 
{
	createdSprites.clear();	// erase any previously generated sprites

	for (int i = 0; i < frequency; i++) {

		Sprite *created = NULL;
		EnemyType species;
		int random;

		random = rand() % spritesToBe.size();
		species = spritesToBe[random];

		switch (species)
		{
			case isHotdog:
				created = new Hotdog;
				// insert randomized placement and speed/motion here?
				// would be done just using created->setX() etc.
				break;
			case isHamburger:
				created = new Hamburger;
				// same as above
				break;
			case isCar1:
				created = new Car1;
				// same as above
				break;
			case isCar2:
				created = new Car2;
				// same as above
				break;
			case isFootballer:
				created = new Footballer;
				// same as above
				break;
		}

		createdSprites.push_back(created);	// push newly created sprite's pointer into createdSprites vector

	}

}

void EnemyGenerator::packageSprites(vector<Sprite*> & _enemies)
{
	for (int i = 0; i < createdSprites.size(); i++)		// pushes creations into enemies vector in main 
		_enemies.push_back(createdSprites[i]);

}