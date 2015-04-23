#include "Sprite.h"
#include "Can.h"

Can::Can(SDLClass &myC) : Sprite(myC)
{
	setTextureClips("resources/can.png", "resources/can.png");
	setSpeed(2,4);
        setFacingRight(0);
}

void Can::setTextureClips(string path1, string path2)
{
	loadSheetFromFile(path1);
	loadFlippedSheetFromFile(path2);

	int totalClips=1;
	setNumClips(totalClips);

	addClip(0, 0, 17, 30);
        addFlippedClip(0, 0, 17, 30);

	setPos(getHalfOfScreen()*2, 0); //set at top of screen

}

//if s==1, move left, otherwise just draw
void Can::draw(int s)
{
        int initialSpeedX = getSpeedX();
	if (s != 0)
	{
		setSpeed(s+initialSpeedX,getSpeedY());
	}

	if (getFacingRight())
            moveRight();
        else
            moveLeft();

        if (getY() > 450)
            //setSpeed(getSpeedX()+s,-1);
	    setSpeed(initialSpeedX+s/2, -1);
        moveDown();

	Sprite::draw(s);

       setSpeed(initialSpeedX,getSpeedY());
}
