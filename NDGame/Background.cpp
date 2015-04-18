#include "Background.h"
#include "StaticScreen.h"

Background::Background(SDLClass &myC)
	: StaticScreen(myC)
{
	loadFromFile("resources/bg.jpg");
	setIsScrollingScreen(1);
	//setScrollingOffset(4);
	setSpeed(2);
}
