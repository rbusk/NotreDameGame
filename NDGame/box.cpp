/* implementation file for box class
 * Ryan Busk
 */

#include <iostream>
#include <cmath>
#include <vector>
#include "box.h"

box::box(int x, int y, int height, int width)
{
	init(x,y,height, width);
}

vector<int> box::getTopLeft()
{
	return topLeft;
}

vector<int> box::getTopRight()
{
	return topRight;
}

vector<int> box::getBottomLeft()
{
	return bottomLeft;
}

vector<int> box::getBottomRight()
{
	return bottomRight;
}

vector<vector <int> > box::getBottom()
{
	return bottom;
}

vector<vector <int> > box::getTop()
{
	return top;
}

vector<vector <int> > box::getLeft()
{
	return left;
}

vector<vector <int> > box::getRight()
{
	return right;
}

void box::init(int x, int y, int h, int w)
{
	setX(x);
	setY(y);
	setD(h,w);
}

void box::setX(int x)
{
	xPos = x;
	makeBox();
}

void box::setY(int y)
{
	yPos = y;
	makeBox();
}

void box::setD(int h, int w)
{
	height = h;
	width = w;
}

void box::makeBox()
{
	//top left
	topLeft.push_back(xPos);
	topLeft.push_back(yPos);
	//top right
	topRight.push_back(xPos+width);
	topRight.push_back(yPos);
	//bottom left
	bottomLeft.push_back(xPos);
	bottomLeft.push_back(yPos-height);
	//bottome right
	bottomRight.push_back(xPos+width);
	bottomRight.push_back(yPos-height);

	//top
	top.push_back(topLeft);
	top.push_back(topRight);

	//bottom
	bottom.push_back(bottomLeft);
	bottom.push_back(bottomRight);

	//left
	left.push_back(topLeft);
	left.push_back(bottomRight);

	//right
	right.push_back(topRight);
	right.push_back(bottomRight);
}

