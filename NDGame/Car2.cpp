#include "Sprite.h"
#include "Car2.h"

Car2::Car2(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/car2.png", "resources/car2.png");
	setSpeed(4,0);
}

void Car2::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 1;		// enter number of sprites on sheet
	setNumClips(totalClips);


	addClip(0, 0, 150, 43);
	
	setPos(getHalfOfScreen()*5,475); 	// starting position

}

void Car2::draw(int s)
{
    int initialSpeedX = getSpeedX();

    setSpeed(initialSpeedX-s,getSpeedY());
    moveRight();

    Sprite::draw(s);

    setSpeed(initialSpeedX,getSpeedY());
    spriteBox.w = 140;          // compensates for this particular car being hard to avoid
}




