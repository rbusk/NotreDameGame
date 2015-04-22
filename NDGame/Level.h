//Level Class .h file
//
#include <vector>
#include <iostream>
using namespace std;

class Level
{
	public:
		Level(int levelNumber);
		vector<int> getFrequencyPowerUp();
		vector<int> getFrequencyEnemy();
		int getLevel();
		int getSpeedMult();
		void setSpeedMult();
		void setFrequencyPowerUp();
		void setFrequencyEnemy();
	private:
		vector<int> FPowerUp;
		vector<int> FEnemy;
		int level;
		int speedMult;
};

