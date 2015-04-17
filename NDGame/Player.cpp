#include "Sprite.h"
#include "Player.h"

Player::Player(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/manSpriteSheet.png", "resources/manSpriteSheet2.png");
	setSpeed(4,4);
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

	setMaxHeight(100);
	setMinHeight(275);
	spriteBox.x = getHalfOfScreen();	// spriteBox has to be set here so that it matches starting pos
	spriteBox.y = 275;
	spriteBox.w = 194;
	spriteBox.h = 198;
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
		if (!getFacingRight() && getXPos()>=getSpeedX())
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
void Player::collisionLoopRect(vector<Sprite*> enemyVector)
{
	int check = 0;

	Sprite* ptr; //use to determine what kind of sprite

	for(int i = 0; i < enemyVector.size(); i++)
	{
		check = 0;
		//add is loaded if statement
		check = collisionCheck(enemyVector[i]);
		
		ptr=enemyVector[i];

		//check to see what kind of sprite player has collided with
		if (check==1)
		{
			if (typeid(*ptr)==typeid(Hotdog))
			{
				cout << "collided with hotdog. yum" << endl;
			}

			else if (typeid(*ptr)==typeid(Car1))
			{
				cout << "collided with car. vroom" << endl;
			}
		}


		if (check == 1 && getXPos() > enemyVector[i]->getXPos())
		{
			cout << "Colliding Left" << endl;
		}
		if (check == 1 && getXPos() < enemyVector[i]->getXPos())
		{
			cout << "Colliding Right" << endl;
		}
		if (check == 1 && getYPos()+getH() == enemyVector[i]->getYPos())
		{
			cout << "On Top" << endl;
		}
		if (check == 0)
			cout << "Not Colliding" << endl;
	}
}

int Player::collisionCheck(Sprite* enemy)
{
	SDL_bool value;
	SDL_Rect enemyRect;

	enemyRect.x = enemy->spriteBox.x;
	enemyRect.y = enemy->spriteBox.y;
	enemyRect.h = enemy->spriteBox.h;
	enemyRect.w = enemy->spriteBox.w;

	value = SDL_HasIntersection(&spriteBox,&enemyRect);

	if (value == SDL_TRUE)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
