#include "SpriteGenerator.h"
#include "SDLClass.h"
#include "Sprite.h"
#include "Player.h"
#include <stdlib.h>

SpriteGenerator::SpriteGenerator(SDLClass &myC) 
{
	mySDL = &myC;
	screenW = mySDL->getW();
	screenH = mySDL->getH();
	freqLower = 100;
	freqHigher = 150;
	spawnTimer.setTimeIncrement(freqHigher);
	spawnTimer.addTime();
	srand(time(NULL));
}

SpriteGenerator::~SpriteGenerator() 
{
	// Destructor
}

void SpriteGenerator::setFrequency(int lower, int higher)
{
	freqLower = lower;
	freqHigher = higher;
}

void SpriteGenerator::setSprites(vector<SpriteType> desired)
{
	spritesToBe = desired;
}

void SpriteGenerator::generateSprites(Player* man) 
{
	createdSprites.clear();	// erase any previously generated sprites

	
	if (spawnTimer.getTimeIsUp()) 	// only spawns random on end of enemy timer
	{	
		Sprite* created = NULL;
		SpriteType species;
		int random, randX, randY;
		int manX = man->getX(), manY = man->getY();

		random = rand() % spritesToBe.size();
		randX = rand() % (screenW*2) + screenW;
		randY = rand() % screenH;
		species = spritesToBe[random];

		switch (species)
		{
			case isCar1:
			{
				created = new Car1(*mySDL);
				created->setPos(manX+screenW,400);		// right now they all spawn a screen away
				break;									// from the man's position
			}
			case isCar2:
			{
				created = new Car2(*mySDL);
				created->setPos(manX+screenW,400);
				break;
			}
			case isFootballer:
			{
				created = new Footballer(*mySDL);
				created->setPos(manX+screenW,400);
				break;
			}
			case isHotdog:
			{
				created = new Hotdog(*mySDL);
				created->setPos(manX+screenW,randY);
				break;
			}
			case isHamburger:
			{
				created = new Hamburger(*mySDL);
				created->setPos(manX+screenW,randY);
				break;
			}
			case isFootballPowerup:
			{
				created = new FootballPowerup(*mySDL);
				created->setPos(manX+screenW,randY);
				break;
			}

		}

		createdSprites.push_back(created);

		int randomTime = rand() % (freqHigher-freqLower) + freqLower;	// generates new random time within range
		spawnTimer.setTimeIncrement(randomTime);						// for time to next enemy spawn
		spawnTimer.addTime();
	}

	if (man->getState() == isWalking)
		spawnTimer.updateTime();	// update timer if man is walking	
	

}

void SpriteGenerator::packageSprites(vector<Sprite*>& _sprites)
{
	for (int i = 0; i < createdSprites.size(); i++)		// pushes creations into enemies vector in main 
		_sprites.push_back(createdSprites[i]);


}

void SpriteGenerator::destroyPastSprites(Player* man, vector<Sprite*>& _sprites)
{
	int tooFar = man->getX() + (screenW*2);
	for (int i = 0; i < _sprites.size(); i++) {
		if ( (_sprites[i]->getX() > tooFar) || (_sprites[i]->getX() < (-1*tooFar) ) ) {
			_sprites[i]->destroySprite();
			delete _sprites[i];
			_sprites.erase(_sprites.begin()+i);
			i--;
		}
	}
}







