#include "Sprite.h"
#include "Player.h"

Player::Player(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/manSpriteSheet.png", "resources/manSpriteSheet2.png");
	setSpeed(4);
	jumpingState=isNotJumping;
	stopScreen=1;
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

void Player::draw()
{
	switch (jumpingState)
	{
		//if sprite is jumping up
		case isJumpingUp:
			moveUp();

			//if sprite reaches maxHeight, switch state to jumping down
			if (getYPos()<maxHeight)
			{
				jumpingState=isJumpingDown;
			}
			break;

			//if sprite is jumping down
		case isJumpingDown:
			moveDown();

			if (getYPos()>minHeight)
			{
				jumpingState=isNotJumping;
			}
			break;
			
		default:
			break;
	}

	basicDraw();

	//if isWalking, increment clip
	if (getState()==isWalking)
	{
		incrementCurrentClip();

		//if facing left, character must move left (rather than the screen scrolling)
		//but also can't let character fall off screen
		if (!getFacingRight() && getXPos()>=getSpeed())
		{
			moveLeft();
		}

		//if facing right but position is too far left, increment x position
		else if (getFacingRight() && getXPos()<getHalfOfScreen())
		{
			moveRight();
		}
	}

	checkCurrentClip();
}

void Player::update()
{
	//if facing left, stop screen
	if (!getFacingRight() && getXPos()>=0)
	{
		stopScreen=1;
	}

	//if facing right but position is too far left, stop screen
	else if (getFacingRight() && getXPos()<getHalfOfScreen())
	{
		stopScreen=1;
	}

	//otherwise screen should scroll if sprite is walking
	else if (getState()==isWalking)
	{
		stopScreen=0;
	}

	//otherwise stop screen
	else
	{
		stopScreen=1;
	}
}


void Player::setMaxHeight(int n)
{
	maxHeight=n;
}

void Player::setMinHeight(int n)
{
	minHeight=n;
}

int Player::getJumpingState()
{
	return jumpingState;
}

void Player::setJumpingState(int n)
{
	jumpingState=n;
}

int Player::getStopScreen()
{
	return stopScreen;
}
