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

		Sprite* created = NULL;
		EnemyType species;
		int random, randX, randY;
		int manX = man->getX(), manY = man->getY();

		random = rand() % spritesToBe.size();
		randX = rand() % (screenW*3) + screenW;
		randY = rand() % screenH;
		species = spritesToBe[random];

		switch (species)
		{
			case isCar1:
			{
				created = new Car1(*mySDL);
				created->setPos(randX,400);
				break;
			}
			case isCar2:
			{
				created = new Car2(*mySDL);
				created->setPos(randX,400);
				break;
			}
			case isFootballer:
			{
				created = new Footballer(*mySDL);
				created->setPos(randX,400);
				break;
			}

		}

		createdSprites.push_back(created);

	}

}

void EnemyGenerator::packageSprites(vector<Sprite*>& _enemies)
{
	for (int i = 0; i < createdSprites.size(); i++)		// pushes creations into enemies vector in main 
		_enemies.push_back(createdSprites[i]);

	//return _enemies;

}
