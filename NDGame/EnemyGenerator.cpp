#include "EnemyGenerator.h"
#include "SDLClass.h"
#include "Sprite.h"
#include "Player.h"
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
	// Destructor
}

void EnemyGenerator::setFrequency(int f)
{
	frequency = f;
}

void EnemyGenerator::setEnemies(vector<EnemyType> desired)
{
	spritesToBe = desired;
}

void EnemyGenerator::generateSprites(Player* man, int num) 
{
	createdSprites.clear();	// erase any previously generated sprites

	for (int i = 0; i < num; i++) {

		int species;
		int random, randX, randY;
		int manX = man->getX(), manY = man->getY();

		random = rand() % spritesToBe.size();
		randX = rand() % (screenW*3) + screenW;
		randY = rand() % screenH;
		species = spritesToBe[random];

		switch (species)
		{
			case isHotdog:
			{
				Hotdog dog(*mySDL);
				Hotdog *dogPtr = &dog;
				// insert randomized placement and speed/motion here?
				// would be done just using created->setX() etc.
				dogPtr->setPos(randX,randY);
				createdSprites.push_back(dogPtr);
				break;
			}
			case isHamburger:
			{
				Hamburger burger(*mySDL);
				Hamburger *burgerPtr = &burger;
				burgerPtr->setPos(randX,randY);
				createdSprites.push_back(burgerPtr);
				break;
			}
			case isCar1:
			{
				Car1 car1(*mySDL);
				Car1 *car1Ptr = &car1;
				car1Ptr->setPos(randX,400);
				createdSprites.push_back(car1Ptr);
				break;
			}
			case isCar2:
			{
				Car2 car2(*mySDL);
				Car2 *car2Ptr = &car2;
				car2Ptr->setPos(randX,400);
				createdSprites.push_back(car2Ptr);
				break;
			}
			case isFootballer:
			{
				Footballer baller(*mySDL);
				Footballer *ballerPtr = &baller;
				ballerPtr->setPos(randX,345);
				createdSprites.push_back(ballerPtr);
				break;
			}

		}



	}

}

void EnemyGenerator::packageSprites(vector<Sprite*>& _enemies)
{
	for (int i = 0; i < createdSprites.size(); i++)		// pushes creations into enemies vector in main 
		_enemies.push_back(createdSprites[i]);

	//return _enemies;

}