#include "Sprite.h"
#include "Car1.h"

Car1::Car1(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/car1.png", "resources/car1.png");
	setSpeed(0,0);
}

void Car1::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 1;		// enter number of sprites on sheet
	setNumClips(totalClips);


	addClip(0, 0, 250, 79);
		
	
	setPos(getHalfOfScreen()*3,400); 	// starting position

}

void Car1::draw(int s)
{
	setSpeed(s,0);
	moveLeft();		// our background scrolls left so this syncs up with it if need be
	basicDraw();
}




