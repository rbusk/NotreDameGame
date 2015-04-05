#include "Sprite.h"
#include "Player.h"

Player::Player(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/manSpriteSheet.jpg");
}

void Player::setTextureClips(string path)
{
	loadFromFile(path);

	int totalClips = 4;		// enter number of sprites on sheet
	setNumClips(totalClips);

	for(int i = 0; i < totalClips; i++ ) 	// sets clips
		addClip( 194*i, 0, 194, 198);
	
	setCurrentClip(0);	// starting clip
	isAnimated = true;	// starting animated?

	setPos(100,100); 	// starting position
}