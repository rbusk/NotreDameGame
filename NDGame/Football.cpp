#include "Sprite.h"
#include "Football.h"

Football::Football(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/football.png", "resources/football.png");
	setSpeed(0,0);
}

void Football::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totoalClips=1; //n of sprites on sheet
	setNumClips(totalClips);

	addClip(0, 0, 60, 30);

	setPos(getHalfOfScreen()*1.75, 500);

	sprite.x=getHalfOfScreen()*1.75;
	spriteBox.y=500;
	spriteBox.w=60;
	spriteBox.h=30;
}
