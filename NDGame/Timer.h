//Timer to keep track of timing for powerups

#ifndef TIME_H
#define TIME_H

class Timer {

	public:
		Timer();
		int getTime();
		void decrementTime(); //decrease time by 1
		void addTime(); //add time to timer
		void updateTime(); //only decrements timer if time>0
		int getTimeIsUp();
		void setTimeIncrement(int); 
		void setTime(int);

	private:
		int time;
		int timeIncrement; //how much time will be added to the timer
		int timeIsUp; //like a ding to indicate time is up
};

#endif
