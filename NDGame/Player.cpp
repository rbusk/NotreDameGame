#include "Sprite.h"
#include <typeinfo>
#include "Player.h"

Player::Player(SDLClass &myC) : Sprite(myC)
{
	//initialize values
	maxXPos=getHalfOfScreen()/1.25;
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
	addFlippedClip(70, 5, 42, 53);
	addFlippedClip(129, 5, 43, 53);
	
	setPos(maxXPos,400); 	// starting position
}

void Player::draw()
{
	//update timers
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

	//if hotdog timer is up, set speed back to normal
	if (hotdogTimer.getTimeIsUp())
	{
		setSpeed(getSpeedX()/2, getSpeedY());
	}

	//if burger timer is pu, set max height back to normal
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

//check if player has collided with sprites
void Player::collisionLoopRect(vector<Sprite*>& enemyVector)
{
	int check = 0;

	//load sound files
	death.load("Death.wav",2);
	powerUp.load("PowerUp.wav",2);

	Sprite* ptr; //use to determine what kind of sprite

	for(int i = 0; i < enemyVector.size(); i++)
	{
		check = 0;
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
				incrementSpeed(); //make player faster if collided with hotdog
				powerUp.play(); //play power up sound
				hotdogTimer.addTime(); //add time to timer

				//erase hotdog from vector and free memory
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
			}

			//die if collide with car
			else if (typeid(*ptr)==typeid(Car1))
			{
                            dead=1;
			    death.play();
			}

			else if (typeid(*ptr)==typeid(Car2))
			{
                            dead=1;
			    death.play();
			}

			//if collide with football guy, player dies
			else if (typeid(*ptr)==typeid(Footballer))
			{
				dead=1;
				death.play();
			}

			//if collide with FootballPowerup, give guy num of footballs
			else if (typeid(*ptr)==typeid(FootballPowerup))
			{
				numFootballs=1;
				powerUp.play();

				//erase football powerup from vector and free memory
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
			}

			//if collide with squirrel, dead
			else if (typeid(*ptr)==typeid(Squirrel))
			{
				dead=1;
				death.play();
			}
                        
                        //if collide with soda can, dead
                        else if (typeid(*ptr)==typeid(Can))
			{
				dead = 1;
				death.play();	
			}
			else if (typeid(*ptr)==typeid(Hamburger))
			{
				setMaxHeight(burgerMaxHeight); //make max height higher
				powerUp.play();
				burgerTimer.addTime();

				//erase hamburger from vector and free memory
				ptr->destroySprite();
				enemyVector.erase(enemyVector.begin()+i);
				i--;
			}
		}
	}
}

//check if collided with enemy
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

void Player::setDead(int n)
{
	dead=n;
}

int Player::getMinHeight()
{
	return minHeight;
}

//reset variables in player when game restarts
void Player::resetPlayer()
{
	setSpeed(3, 7);
	setDead(0);
	setState(isResting);
	setMaxHeight(noBurgerMaxHeight);
	setNumFootballs(0);
}
