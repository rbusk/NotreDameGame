#include "Sprite.h"
#include "Hamburger.h"

Hamburger::Hamburger(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/hamburger.png", "resources/hamburger.png");
	setSpeed(0,0);
}

void Hamburger::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 1;		// enter number of sprites on sheet
	setNumClips(totalClips);


	addClip(0, 0, 57, 50);
		
	
	setPos(getHalfOfScreen()*1.3,150); 	// starting position

	spriteBox.x = getHalfOfScreen()*1.3;	// spriteBox has to be set here so that it matches starting pos
	spriteBox.y = 150;
	spriteBox.w = 57;
	spriteBox.h = 50;

}

void Hamburger::draw(int s)
{
	setSpeed(s,0);
	moveLeft();		// our background scrolls left so this syncs up with it if need be
	Sprite::draw(s);
}



