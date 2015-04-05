#include "Background.h"
#include "StaticScreen.h"

Background::Background(SDLClass &myC)
	: StaticScreen(myC)
{
	loadFromFile("resources/bg.jpg");
	setIsScrollingScreen(1);
	setIsScrolling(1);
}
