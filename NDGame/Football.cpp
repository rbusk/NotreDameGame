#include "Sprite.h"
#include "Football.h"

Football::Football(SDLClass &myC, int x, int y) : Sprite(myC)
{
	setTextureClips("resources/football.png", "resources/football.png");
	setSpeed(5,0);
	setPos(x, y); //set position
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

//if s==0, use actualSpeed. 
//if s==1, the screen is scrolling. use actualSpeed+extraSpeed. extra accounts for the extra speed
//so that the football doesn't slow down when the player moves
void Football::draw(int s)
{
	moveRight();
	Sprite::draw(s);
}
