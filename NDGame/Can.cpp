#include "Sprite.h"
#include "Can.h"

Can::Can(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/can.png", "resources/can.png");
	setSpeed(0,4);
}

void Can::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips=1;
	setNumClips(totalClips);

	addClip(0, 0, 40, 70);

	setPos(getHalfOfScreen()*2, 0); //set at top of screen

	spriteBox.x = getHalfOfScreen()*2;
	spriteBox.y=0;
	spriteBox.w=40;
	spriteBox.h=70;
}

//if s==1, move left, otherwise just draw
void Can::draw(int s)
{
	if (s==1)
	{
		moveLeft();
	}

	moveDown();
	Sprite::draw(s);
}
