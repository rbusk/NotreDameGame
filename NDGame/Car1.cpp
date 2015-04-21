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


	addClip(0, 0, 150, 43);
		
	
	setPos(getHalfOfScreen()*3,500); 	// starting position

/*	spriteBox.x = getHalfOfScreen()*3;	// spriteBox has to be set here so that it matches starting pos
	spriteBox.y = 400;
	spriteBox.w = 250;
	spriteBox.h = 79;*/

}

//if s is 1, then move left, otherwise
void Car1::draw(int s)
{
	if (s==1)
	{
		moveLeft();
	}

	Sprite::draw(s);
}




