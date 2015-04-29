// level.cpp
// Ryan Busk

#include "Level.h"

Level::Level(int levelNumber)
{
	level = levelNumber; //set level number
	setSpeedMult(); //set speed mult
	setFrequencyPowerUp(); //set freqs
	setFrequencyEnemy();
}

vector<int> Level::getFrequencyPowerUp()
{
	return FPowerUp; //return freq
}

vector<int> Level::getFrequencyEnemy()
{
	return FEnemy; //return freq
}

int Level::getLevel()
{
	return level; //return level
}

int Level::getSpeedMult()
{
	return speedMult; //return level speed mult
}

void Level::setSpeedMult()
{
	speedMult = 0; //set speed multiplier
}

void Level::setFrequencyEnemy()
{
	int min = 50 + 100/(level*2); // min range
	int max = 100 + 100/(level*2);// max range
	FEnemy.push_back(min);//push min
	FEnemy.push_back(max);//push max
}

void Level::setFrequencyPowerUp()
{
	int min = 100 + 200 + (level-1)*75;//min range
	int max = 100 + 300 + (level-1)*75;//max range
	FPowerUp.push_back(min);//push min
	FPowerUp.push_back(max);//push max
}



