// level.cpp
// Ryan Busk

#include "Level.h"

Level::Level(int levelNumber)
{
	level = levelNumber;
	setSpeedMult();
	setFrequencyPowerUp();
	setFrequencyEnemy();
}

vector<int> Level::getFrequencyPowerUp()
{
	return FPowerUp;
}

vector<int> Level::getFrequencyEnemy()
{
	return FEnemy;
}

int Level::getLevel()
{
	return level;
}

int Level::getSpeedMult()
{
	return speedMult;
}

void Level::setSpeedMult()
{
	speedMult = 0;
}

void Level::setFrequencyEnemy()
{
	int min = 50 + 100/(level*2);
	int max = 100 + 100/(level*2);
	FEnemy.push_back(min);
	FEnemy.push_back(max);
}

void Level::setFrequencyPowerUp()
{
	int min = 100 + 200 + (level-1)*75;
	int max = 100 + 300 + (level-1)*75;
	FPowerUp.push_back(min);
	FPowerUp.push_back(max);
}



