#include "Timer.h"

Timer::Timer()
{
	time = 0;
	timeIncrement=500;
	timeIsUp=0;
}

void Timer::decrementTime()
{
	time--;
}

int Timer::getTime()
{
	return time;
}

void Timer::addTime()
{
	time+=timeIncrement;
}

void Timer::updateTime()
{
	if (time==1)
	{
		timeIsUp=1;
	}

	else
	{
		timeIsUp=0;
	}

	if (time>0)
	{
		decrementTime();
	}
}

int Timer::getTimeIsUp()
{
	return timeIsUp;
}

void Timer::setTimeIncrement(int n)
{
	timeIncrement = n;
}

void Timer::setTime(int n)
{
	time=n;
}
