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

}

void Hamburger::draw(int s)
{
	int initialSpeedX= getSpeedX();

	setSpeed(s, getSpeedY());       // move along with screen if need be

	moveLeft();		
	Sprite::draw(s);
	setSpeed(initialSpeedX, getSpeedY());
}
