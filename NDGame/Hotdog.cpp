#include "Sprite.h"
#include "Hotdog.h"

Hotdog::Hotdog(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/hotdog.png", "resources/hotdog.png");
	setSpeed(0,0);
}

void Hotdog::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 1;		// enter number of sprites on sheet
	setNumClips(totalClips);


	addClip(0, 0, 60, 30);
		
	
	setPos(getHalfOfScreen()*1.75,400); 	// starting position
}

//if s==1 then move left, otherwise just draw
void Hotdog::draw(int s)
{
	int initialSpeedX = getSpeedX();

	setSpeed(s, getSpeedY());

	moveLeft();		// our background scrolls left so this syncs up with it if need be
	Sprite::draw(s);
	
	setSpeed(initialSpeedX, getSpeedY());

}
