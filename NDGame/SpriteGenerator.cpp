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
        /* Set sprites that you want this SpriteGenerator to produce. For example:
           if you wanted this to generate either a squirrel or a footballer, you
           would create a vector of SpriteType, push_back(isSquirrel) and push_back(isFootballer),
           and then send this vector into the generator with this function      */
	spritesToBe = desired;
}

void SpriteGenerator::generateSprites(Player* man) 
{
	createdSprites.clear();	// erase any previously generated sprites

	
	if (spawnTimer.getTimeIsUp()) 	// only spawns random on end of enemy timer
	{	
		Sprite* created = NULL;
		SpriteType species;
		int random, randX, randY, randXS, randYS;
		int manX = man->getX(), manY = man->getY();

		random = rand() % spritesToBe.size();           // randomly choose index within spriteToBe
		randX = rand() % (screenW*2) + screenW;         // randomX slightly offscreen
		randY = rand() % 200 + 200;                     // randomY within reach of player
                randXS = rand() % 5 + 1;                        // random X speed
                randYS = rand() % 5 + 1;                        // random Y speed
		species = spritesToBe[random];                  // the generated sprite will be whichever type 
                                                                // is in that index of spritesToBe
		switch (species)
		{
			case isCar1:
			{
				created = new Car1(*mySDL);
				created->setPos(manX+screenW,425);		// right now they all spawn a screen away
				break;						// from the man's position
			}
			case isCar2:
			{
				created = new Car2(*mySDL);
				created->setPos(manX+screenW,425);
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
				created = new Hotdog(*mySDL);                   // some have set y-positions while others have
				created->setPos(manX+screenW,randY);            // a random one
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

			case isSquirrel:
			{
				created = new Squirrel(*mySDL);
				created->setPos(manX+screenW/2, randY-300);
				break;
			}
                        case isCan:
                        {
                            created = new Can(*mySDL);
                            created->setPos(manX+screenW, randY-300);
                            created->setSpeed(randXS,randYS+2);
                            break;
                        }
		}

		createdSprites.push_back(created);

		int randomTime = rand() % (freqHigher-freqLower) + freqLower;	// generates new random time within range
		spawnTimer.setTimeIncrement(randomTime);		        // for time to next enemy spawn
		spawnTimer.addTime();
		spawnTimer.updateTime();
	}

	if (man->getState() == isWalking)
		spawnTimer.updateTime();	// update timer if man is walking, like mario in that when the man stops,	
	                                        // enemies would not generate infinitely and keep coming

}

void SpriteGenerator::packageSprites(vector<Sprite*>& _sprites)
{
	for (int i = 0; i < createdSprites.size(); i++)		// pushes creations into desired vector in main 
		_sprites.push_back(createdSprites[i]);


}

void SpriteGenerator::destroyPastSprites(Player* man, vector<Sprite*>& _sprites)
{
	int tooFarX = man->getX() + (screenW*2);        // over 2 screens aways from man
	int tooFarY = screenH+200;                      // over 200 pixels above or below screen
	for (int i = 0; i < _sprites.size(); i++) {
		if ( (_sprites[i]->getX() > tooFarX) || (_sprites[i]->getX() < (-1*tooFarX) ) ) {
			_sprites[i]->destroySprite();
			delete _sprites[i];
			_sprites.erase(_sprites.begin()+i);
			i--;
		}
		else if ( (_sprites[i]->getY() > tooFarY) || (_sprites[i]->getY() < (-200) ) ) {
			_sprites[i]->destroySprite();
			delete _sprites[i];
			_sprites.erase(_sprites.begin()+i);
			i--;
		}
	}
}







