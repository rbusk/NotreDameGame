#include "Sprite.h"
#include "Squirrel.h"

Squirrel::Squirrel(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/squirrel.png", "resources/squirrel.png");
	setSpeed(2, 6);
}

void Squirrel::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips=1;
	setNumClips(totalClips);

	addClip(0, 0, 65, 75);

	setPos(getHalfOfScreen(), 0);

}

void Squirrel::draw(int s)
{
	int initialSpeedX = getSpeedX();

	if (s!=0)
	{
		setSpeed(s+initialSpeedX, getSpeedY()); // set speed relative to moving screen
	}

	moveDown();
	moveLeft();

	Sprite::draw(s);

	setSpeed(initialSpeedX, getSpeedY());
}
