#include "Sprite.h"
#include <typeinfo>
#include "Player.h"

Player::Player(SDLClass &myC) : Sprite(myC)
{
	maxXPos=getHalfOfScreen()/2;
	setTextureClips("resources/manSpriteSheet.png", "resources/manSpriteSheet2.png");
	setSpeed(3, 7);
	jumpingState=isNotJumping;
	stopScreen=1;
	setMaxSpeed(6);
	isInCollision=0;
	dead=0;
	numFootballs=0;
	setW(45);
	burgerMaxHeight=200;
	noBurgerMaxHeight=250;
	setMaxHeight(noBurgerMaxHeight); //original max height is one w/o eating burger
	setMinHeight(400);
}

void Player::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips = 3;		// enter number of sprites on sheet
	setNumClips(totalClips);

	addClip(10, 5, 45, 53);
	addClip(70, 5, 45, 53);
	addClip(129, 5, 46, 53);
	addFlippedClip(10, 5, 45, 53);
	addFlippedClip(70, 5, 45, 53);
	addFlippedClip(129, 5, 46, 53);
	
	setPos(maxXPos,400); 	// starting position
}

void Player::draw()
{
	hotdogTimer.updateTime();
	burgerTimer.updateTime();

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

	if (hotdogTimer.getTimeIsUp())
	{
		setSpeed(getSpeedX()/2, getSpeedY());
	}

	if (burgerTimer.getTimeIsUp())
	{
		setMaxHeight(noBurgerMaxHeight);
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
		else if (getFacingRight() && getXPos()<maxXPos)
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
	else if (getFacingRight() && getXPos()<maxXPos)
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
void Player::collisionLoopRect(vector<Sprite*>& enemyVector)
{
	int check = 0;

	Sprite* ptr; //use to determine what kind of sprite

	for(int i = 0; i < enemyVector.size(); i++)
	{
		check = 0;
		//add is loaded if statement
		check = collisionCheck(enemyVector[i]);
		
		ptr=enemyVector[i];
		
		if (check == 0)
		{
			if (isInCollision==1)
			{
				isInCollision=0;
			}
		}
		
		//check to see what kind of sprite player has collided with
		if (check==1)
		{
			if (typeid(*ptr)==typeid(Hotdog))
			{	
				incrementSpeed(); //make player faster!
				hotdogTimer.addTime();

				//erase hotdog from vector and free memory
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
			}

			else if (typeid(*ptr)==typeid(Car1))
			{
                            dead=1;
			}

			else if (typeid(*ptr)==typeid(Car2))
			{
                            dead=1;
			}

			//if collide with football guy, player dies
			else if (typeid(*ptr)==typeid(Footballer))
			{
				dead=1;
			}

			//if collide with FootballPowerup, give guy num of footballs
			else if (typeid(*ptr)==typeid(FootballPowerup))
			{
				numFootballs=1;

				//erase football powerup from vector and free memory
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
			}

			//if collide with squirrel, dead
			else if (typeid(*ptr)==typeid(Squirrel))
			{
				dead=1;
			}
                        
                        //if collide with soda can, dead
                        else if (typeid(*ptr)==typeid(Can))
                            dead = 1;        

			else if (typeid(*ptr)==typeid(Hamburger))
			{
				setMaxHeight(burgerMaxHeight); //make max height higher
				burgerTimer.addTime();

				//erase hamburger from vector and free memory
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
			}
		}
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

int Player::isDead()
{
	return dead;
}

int Player::getNumFootballs()
{
	return numFootballs;
}

void Player::setNumFootballs(int n)
{
	numFootballs=n;
}


