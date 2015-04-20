#include "Sprite.h"
#include "Car2.h"

Car2::Car2(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/car2.png", "resources/car2.png");
	setSpeed(0,0);
}

void Car2::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 1;		// enter number of sprites on sheet
	setNumClips(totalClips);


	addClip(0, 0, 250, 71);
		
	
	setPos(getHalfOfScreen()*5,400); 	// starting position

	spriteBox.x = getHalfOfScreen()*5;	// spriteBox has to be set here so that it matches starting pos
	spriteBox.y = 400;
	spriteBox.w = 250;
	spriteBox.h = 71;

}

void Car2::draw(int s)
{
	if (s)
	{
		moveLeft();		// our background scrolls left so this syncs up with it if need be
	}
		
	Sprite::draw(s);
}




