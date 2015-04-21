#include "Sprite.h"
#include "Squirrel.h"

Squirrel::Squirrel(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/squirrel.png", "resources/squirrel.png");
	setSpeed(0, 4);
}

void Squirrel::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips=1;
	setNumClips(totalClips);

	addClip(0, 0, 93, 107);

	setPos(getHalfOfScreen(), 0);

}

void Squirrel::draw(int s)
{
	if (s==1)
	{
		moveLeft();
	}

	moveDown();

	Sprite::draw(s);
}
