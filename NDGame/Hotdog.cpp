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


	addClip(0, 0, 100, 60);
		
	
	setPos(getHalfOfScreen()*1.75,400); 	// starting position

}

void Hotdog::draw(int s)
{
	setSpeed(s,0);
	moveLeft();
	basicDraw();
}

void Hotdog::setIsLoaded(bool loaded)
{
	isLoaded = loaded;
}


