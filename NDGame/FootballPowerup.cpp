#include "Sprite.h"
#include "FootballPowerup.h"

FootballPowerup::FootballPowerup(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/football.png", "resources/football.png");
	setSpeed(0,0);
}

void FootballPowerup::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips=1; //n of sprites on sheet
	setNumClips(totalClips);

	addClip(0, 0, 67, 41);

	setPos(getHalfOfScreen()*2, 400);

	spriteBox.x=getHalfOfScreen()*2;
	spriteBox.y=400;
	spriteBox.w=67;
	spriteBox.h=41;
}

void FootballPowerup::draw(int s)
{
	if (s==1)
	{
		moveLeft();
	}

	Sprite::draw(s);
}
