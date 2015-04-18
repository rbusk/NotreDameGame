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

	int totalClips=1; //n of sprites on sheet
	setNumClips(totalClips);

	addClip(0, 0, 67, 41);

	setPos(getHalfOfScreen()*1.75, 300);

	spriteBox.x=getHalfOfScreen()*1.75;
	spriteBox.y=300;
	spriteBox.w=67;
	spriteBox.h=41;
}

void Football::draw(int s)
{
	Sprite::draw(s);
}
