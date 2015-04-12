/* Class that makes box around sprite
 * Ryan Busk
 */

#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <vector>
using namespace std;

class box
{
	public:
		box(int = 0, int = 0, int = 0,int = 0);
		vector<vector<int> > getTop();
		vector<vector<int> > getBottom();
		vector<vector<int> > getLeft();
		vector<vector<int> > getRight();
		vector<int> getTopLeft();
		vector<int> getTopRight();
		vector<int> getBottomLeft();
		vector<int> getBottomRight();
		void init(int, int, int, int);
		void setX(int);
		void setY(int);
		void setD(int, int);
		void makeBox();
		void clearBox();
	private:
		vector<vector<int> > bottom; //bottomLeft bottomRight
		vector<vector<int> > top; //topLeft(1) topRight(2)
		vector<vector<int> > right; //topRight bottomRight
		vector<vector<int> > left; //topLeft bottomLeft
		vector<int> topLeft; //x,y
		vector<int> topRight;
		vector<int> bottomLeft;
		vector<int> bottomRight;
		int xPos;
		int yPos;
		int width;
		int height;
};



#endif
