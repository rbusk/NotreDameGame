#include "Sprite.h"
#include "Player.h"

Player::Player(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/manSpriteSheet.jpg", "resources/manSpriteSheet2.jpg");
}

void Player::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 4;		// enter number of sprites on sheet
	setNumClips(totalClips);

	for(int i = 0; i < totalClips; i++ )
	{	// sets clips
		addClip( 194*i, 0, 194, 198);
		addFlippedClip(194*i, 0, 194, 198);
	}
	
	setPos(getHalfOfScreen(),275); 	// starting position

	setMaxHeight(200);
	setMinHeight(275);
}
