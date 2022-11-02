#include <iostream>
#include <stdio.h>
#include "light.h"

using namespace std;

Light::Light()
{

	//_cyclePeriods.insert( pair<string, int>("green", 10) );
	//_cyclePeriods.insert( pair<string, int>("red", 10) );
	greenTime = 10.0;
	_carsWaiting = 0;
	state = "red";
}

void Light::setNewTime(/*string color,*/ double time)
{
	/*_cyclePeriods[color] = time;
	if(_cyclePeriods[color] < 0)
	{
	  _cyclePeriods[color] = 0;
	}*/
	greenTime = time;
	if (greenTime < 2.0)
	{
		greenTime = 2.0;
	}
	if (greenTime > 18.0)
	{
		greenTime = 18.0;
	}
}

double Light::getTime(/*string color*/)
{
	//return _cyclePeriods[color];
	return greenTime;
}

int Light::getCarsWaiting()
{
	return _carsWaiting;
}

void Light::addCarsWaiting(int num)
{
	_carsWaiting += num;
}

void Light::letCarThrough()
{
	if (_carsWaiting > 0)
	{
		_carsWaiting--;
	}
}

void Light::setState(string color)
{
	state = color;
}

string Light::getState()
{
	return state;
}
