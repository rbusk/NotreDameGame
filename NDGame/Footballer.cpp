#include "Sprite.h"
#include "Footballer.h"

Footballer::Footballer(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/footballPlayerSpriteSheet1.png", "resources/footballPlayerSpriteSheet2.png");
	setSpeed(5,0);
	setFacingRight(0);
}

void Footballer::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 4;		// enter number of sprites on sheet
	setNumClips(totalClips);

	addClip( 0, 0, 83, 125);
	addClip( 146, 0, 126, 125);			// Had to unfortunately add these manually because
	addClip( 285, 0, 84, 125);			// not every clip is the same width
	addClip( 431, 0, 122, 125);
	addFlippedClip(0, 0, 122, 125);
	addFlippedClip(185, 0 , 84, 125);
	addFlippedClip(325, 0, 126, 125);
	addFlippedClip(514, 0, 83, 125);
	
		
	
	setPos(getHalfOfScreen()*6,345); 	// starting position

	spriteBox.x = getHalfOfScreen()*6;	// spriteBox has to be set here so that it matches starting pos
	spriteBox.y = 345;
	spriteBox.w = 120;
	spriteBox.h = 125;

}

void Footballer::draw(int s)
{
	int initialSpeedX = getSpeedX();
	if (s != 0)		// if background speed != 0, adjust player speed accordingly
		setSpeed(s+initialSpeedX,getSpeedY());

	moveLeft();		// our background scrolls left so this syncs up with it if need be
	Sprite::draw(s);

	setSpeed(initialSpeedX,getSpeedY());	// returns sprites actual speed to normal
	incrementCurrentClip();
	checkCurrentClip();
}
