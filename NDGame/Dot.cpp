#include "Dot.h"

Dot::Dot()
{
	mPosX=0;
	mPosY=0;

	mVelX=0;
	mVelY=0;

void Dot::move()
{
	mPosX+=mVelX;
	
	//if dot went too far to the left or right
	if ((mPosX<0 || mPosX + DOT_WIDTH > LEVEL_WIDTH))
	{
		//move back
		mPosX-=mVelX;
	}

	if ((mPosY<0 || mPosY + DOT_WIDTH > LEVEL_WIDTH))
	{
		//move back
		mPosY-=mVelY;
	}
}

void Dot::render(int camX, int camY)
{
	gDot
