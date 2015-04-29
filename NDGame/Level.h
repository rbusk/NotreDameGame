//Level Class .h file
//
#include <vector>
#include <iostream>
using namespace std;

class Level
{
	public:
		Level(int levelNumber); //constructor with level number
		vector<int> getFrequencyPowerUp(); //set powerup frequency
		vector<int> getFrequencyEnemy(); //set frequency of enemy
		int getLevel(); //get level
		int getSpeedMult(); //get speed multiplier
		void setSpeedMult(); //set speed multiplier
		void setFrequencyPowerUp(); //set freq
		void setFrequencyEnemy();
	private:
		vector<int> FPowerUp;//power up frequency range
		vector<int> FEnemy;//enemy frequency range
		int level; //level number
		int speedMult; //speed multiplier
};

