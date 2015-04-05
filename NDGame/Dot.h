#ifndef DOT_H
#define DOT_H

class Dot {
	public:
		static const int DOT_WIDTH = 20;
		static const int height DOT_HEIGHT = 20;

		//maximum axis velocity
		static const int vel DOT_VEL= 10;

		Dot();

		void handleEvent (SDL_Event &e); //adjusts velocity

		void move(); //move dot

		void render(int camX, int camY); // renders relative to camera

		int getPosX();
		int getPosY();

	private:
		int mPosX, mPosY; //x and y offsets of dot
		int mVelX, mVelY; //velocity of dot

};

#endif
