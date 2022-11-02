#include <stdio.h>
#include "intersection.h"
#include <iostream>
#include <cmath>

Intersection::Intersection()
{
	Light A, B, C, D;
	A.setState("green");
	C.setState("green");
	_lights.push_back(A);
	_lights.push_back(B);
	_lights.push_back(C);
	_lights.push_back(D);
}

Light Intersection::getLight(int index)
{
	return _lights.at(index);
}

void Intersection::runCycles(int timePeriod)
{
	string stateA = _lights.at(0).getState();
	string stateB = _lights.at(1).getState();
	string stateC = _lights.at(2).getState();
	string stateD = _lights.at(3).getState();
	if (stateA == "green" && stateC == "green")
	{
		cout << "AC are green" << endl;
		startAC(timePeriod);
		adjust();
	}
	else if (stateB == "green" && stateD == "green")
	{
		cout << "BD are green" << endl;
		startBD(timePeriod);
		adjust();
	}
	else if (stateA == "green")
	{
		cout << "A is green" << endl;
		startA(timePeriod);
	}
	else if (stateC == "green")
	{
		cout << "C is green" << endl;
		startC(timePeriod);
	}
	else if (stateB == "green")
	{
		cout << "B is green" << endl;
		startB(timePeriod);
	}
	else if (stateD == "green")
	{
		cout << "D is green" << endl;
		startD(timePeriod);
	}
}

void Intersection::startAC(int timePeriod)
{
	while (timePeriod != 0)
	{
		int greenTimeA = _lights.at(0).getTime();
		int greenTimeC = _lights.at(2).getTime();
		while (greenTimeA != 0 && greenTimeC != 0)
		{
			_lights.at(0).letCarThrough();
			_lights.at(2).letCarThrough();
			greenTimeA--;
			greenTimeC--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeA != 0)
		{
			_lights.at(2).setState("red");
			//cout << "Light C turned red" << endl;
			_lights.at(0).letCarThrough();
			greenTimeA--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeC != 0)
		{
			_lights.at(0).setState("red");
			//cout << "Light A turned red" << endl;
			_lights.at(2).letCarThrough();
			greenTimeC--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		//cout << timePeriod << endl;
		_lights.at(0).setState("red");
		//cout << "Light A turned red" << endl;
		_lights.at(2).setState("red");
		//cout << "Light C turned red" << endl;
		_lights.at(1).setState("green");
		//cout << "Light B turned green" << endl;
		_lights.at(3).setState("green");
		//cout << "Light D turned green" << endl;
		int greenTimeB = _lights.at(1).getTime();
		int greenTimeD = _lights.at(3).getTime();
		while (greenTimeB != 0 && greenTimeD != 0)
		{
			_lights.at(1).letCarThrough();
			_lights.at(3).letCarThrough();
			greenTimeB--;
			greenTimeD--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeB != 0)
		{
			_lights.at(3).setState("red");
			//cout << "Light D turned red" << endl;
			_lights.at(1).letCarThrough();
			greenTimeB--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeD != 0)
		{
			_lights.at(1).setState("red");
			//cout << "Light B turned red" << endl;
			_lights.at(3).letCarThrough();
			greenTimeD--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		_lights.at(1).setState("red");
		//cout << "Light B turned red" << endl;
		_lights.at(3).setState("red");
		//cout << "Light D turned red" << endl;
		_lights.at(0).setState("green");
		//cout << "Light A turned green" << endl;
		_lights.at(2).setState("green");
	}
}

void Intersection::startBD(int timePeriod)
{
	while (timePeriod != 0)
	{
		int greenTimeB = _lights.at(1).getTime();
		int greenTimeD = _lights.at(3).getTime();
		while (greenTimeB != 0 && greenTimeD != 0)
		{
			_lights.at(1).letCarThrough();
			_lights.at(3).letCarThrough();
			greenTimeB--;
			greenTimeD--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeB != 0)
		{
			_lights.at(3).setState("red");
			_lights.at(1).letCarThrough();
			greenTimeB--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeD != 0)
		{
			_lights.at(1).setState("red");
			_lights.at(3).letCarThrough();
			greenTimeD--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		_lights.at(1).setState("red");
		_lights.at(3).setState("red");
		_lights.at(0).setState("green");
		_lights.at(2).setState("green");
		int greenTimeA = _lights.at(0).getTime();
		int greenTimeC = _lights.at(2).getTime();
		while (greenTimeA != 0 && greenTimeC != 0)
		{
			_lights.at(0).letCarThrough();
			_lights.at(2).letCarThrough();
			greenTimeA--;
			greenTimeC--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeA != 0)
		{
			_lights.at(2).setState("red");
			_lights.at(0).letCarThrough();
			greenTimeA--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		while (greenTimeC != 0)
		{
			_lights.at(0).setState("red");
			_lights.at(2).letCarThrough();
			greenTimeC--;
			timePeriod--;
			if (timePeriod == 0)
			{
				return;
			}
		}
		_lights.at(0).setState("red");
		_lights.at(2).setState("red");
		_lights.at(1).setState("green");
		_lights.at(3).setState("green");
	}
}

void Intersection::startA(int timePeriod)
{
	int greenTimeA = _lights.at(0).getTime();
	while (greenTimeA != 0)
	{
		_lights.at(2).setState("red");
		_lights.at(0).letCarThrough();
		greenTimeA--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(0).setState("red");
	_lights.at(1).setState("green");
	_lights.at(3).setState("green");
	int greenTimeB = _lights.at(1).getTime();
	int greenTimeD = _lights.at(3).getTime();
	while (greenTimeB != 0 && greenTimeD != 0)
	{
		_lights.at(1).letCarThrough();
		_lights.at(3).letCarThrough();
		greenTimeB--;
		greenTimeD--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeB != 0)
	{
		_lights.at(3).setState("red");
		_lights.at(1).letCarThrough();
		greenTimeB--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeD != 0)
	{
		_lights.at(1).setState("red");
		_lights.at(3).letCarThrough();
		greenTimeD--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(1).setState("red");
	_lights.at(3).setState("red");
	_lights.at(0).setState("green");
	_lights.at(2).setState("green");
	startAC(timePeriod);
	return;
}

void Intersection::startC(int timePeriod)
{
	int greenTimeC = _lights.at(2).getTime();
	while (greenTimeC != 0)
	{
		_lights.at(0).setState("red");
		_lights.at(2).letCarThrough();
		greenTimeC--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(2).setState("red");
	_lights.at(1).setState("green");
	_lights.at(3).setState("green");
	int greenTimeB = _lights.at(1).getTime();
	int greenTimeD = _lights.at(3).getTime();
	while (greenTimeB != 0 && greenTimeD != 0)
	{
		_lights.at(1).letCarThrough();
		_lights.at(3).letCarThrough();
		greenTimeB--;
		greenTimeD--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeB != 0)
	{
		_lights.at(3).setState("red");
		_lights.at(1).letCarThrough();
		greenTimeB--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeD != 0)
	{
		_lights.at(1).setState("red");
		_lights.at(3).letCarThrough();
		greenTimeD--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(1).setState("red");
	_lights.at(3).setState("red");
	_lights.at(0).setState("green");
	_lights.at(2).setState("green");
	startAC(timePeriod);
	return;
}

void Intersection::startB(int timePeriod)
{
	int greenTimeB = _lights.at(1).getTime();
	while (greenTimeB != 0)
	{
		_lights.at(3).setState("red");
		_lights.at(1).letCarThrough();
		greenTimeB--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(1).setState("red");
	_lights.at(0).setState("green");
	_lights.at(2).setState("green");
	int greenTimeA = _lights.at(0).getTime();
	int greenTimeC = _lights.at(2).getTime();
	while (greenTimeA != 0 && greenTimeC != 0)
	{
		_lights.at(0).letCarThrough();
		_lights.at(2).letCarThrough();
		greenTimeA--;
		greenTimeC--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeA != 0)
	{
		_lights.at(2).setState("red");
		_lights.at(0).letCarThrough();
		greenTimeA--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeC != 0)
	{
		_lights.at(0).setState("red");
		_lights.at(2).letCarThrough();
		greenTimeC--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(0).setState("red");
	_lights.at(2).setState("red");
	_lights.at(1).setState("green");
	_lights.at(3).setState("green");
	startBD(timePeriod);
	return;
}

void Intersection::startD(int timePeriod)
{
	int greenTimeD = _lights.at(3).getTime();
	while (greenTimeD != 0)
	{
		_lights.at(1).setState("red");
		_lights.at(3).letCarThrough();
		greenTimeD--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(3).setState("red");
	_lights.at(0).setState("green");
	_lights.at(2).setState("green");
	int greenTimeA = _lights.at(0).getTime();
	int greenTimeC = _lights.at(2).getTime();
	while (greenTimeA != 0 && greenTimeC != 0)
	{
		_lights.at(0).letCarThrough();
		_lights.at(2).letCarThrough();
		greenTimeA--;
		greenTimeC--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeA != 0)
	{
		_lights.at(2).setState("red");
		_lights.at(0).letCarThrough();
		greenTimeA--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	while (greenTimeC != 0)
	{
		_lights.at(0).setState("red");
		_lights.at(2).letCarThrough();
		greenTimeC--;
		timePeriod--;
		if (timePeriod == 0)
		{
			return;
		}
	}
	_lights.at(0).setState("red");
	_lights.at(2).setState("red");
	_lights.at(1).setState("green");
	_lights.at(3).setState("green");
	startBD(timePeriod);
	return;
}

void Intersection::runCycle()
{

	int greenTimeA = _lights.at(0).getTime();
	int greenTimeC = _lights.at(2).getTime();
	while (greenTimeA != 0 && greenTimeC != 0)
	{
		_lights.at(0).letCarThrough();
		_lights.at(2).letCarThrough();
		greenTimeA--;
		greenTimeC--;
	}
	while (greenTimeA != 0)
	{
		_lights.at(2).setState("red");
		_lights.at(0).letCarThrough();
		greenTimeA--;
	}
	while (greenTimeC != 0)
	{
		_lights.at(0).setState("red");
		_lights.at(2).letCarThrough();
		greenTimeC--;
	}
	_lights.at(0).setState("red");
	_lights.at(2).setState("red");
	_lights.at(1).setState("green");
	_lights.at(3).setState("green");
	int greenTimeB = _lights.at(1).getTime();
	int greenTimeD = _lights.at(3).getTime();
	while (greenTimeB != 0 && greenTimeD != 0)
	{
		_lights.at(1).letCarThrough();
		_lights.at(3).letCarThrough();
		greenTimeB--;
		greenTimeD--;

	}
	while (greenTimeB != 0)
	{
		_lights.at(3).setState("red");
		_lights.at(1).letCarThrough();
		greenTimeB--;
	}
	while (greenTimeD != 0)
	{
		_lights.at(1).setState("red");
		_lights.at(3).letCarThrough();
		greenTimeD--;
	}
	_lights.at(1).setState("red");
	_lights.at(3).setState("red");
	_lights.at(0).setState("green");
	_lights.at(2).setState("green");

	//algorithm
	adjust();

	//no algorithm
	/*_lights.at(0).setNewTime(10.0);
	_lights.at(1).setNewTime(10.0);
	_lights.at(2).setNewTime(10.0);
	_lights.at(3).setNewTime(10.0);*/
}

//adjust each of the 4 lights green/red time to optimize traffic flow (make them equal at each light)
void Intersection::adjust()
{
	//each cycle yields the following added to the previous
	//10 cars at light A
	//10 cars at light C
	//0 at B
	//0 at D
	_lights.at(0).score = _lights.at(0).getCarsWaiting();
	_lights.at(1).score = _lights.at(1).getCarsWaiting();
	_lights.at(2).score = _lights.at(2).getCarsWaiting();
	_lights.at(3).score = _lights.at(3).getCarsWaiting();

	int scoreA = _lights.at(0).getCarsWaiting();
	int scoreB = _lights.at(1).getCarsWaiting();
	int scoreC = _lights.at(2).getCarsWaiting();
	int scoreD = _lights.at(3).getCarsWaiting();

	//200
	int scoreAC = scoreA + scoreC;
	//0
	int scoreBD = scoreB + scoreD;



	int car_diff = abs(scoreAC - scoreBD);//difference in cars waiting
	double time_diff = abs(_lights.at(0).getTime() - _lights.at(1).getTime());//difference in green time between lights
	cout << "AC green time: " << _lights.at(0).getTime() << endl;
	cout << "BD green time: " << _lights.at(1).getTime() << endl;
	double adjustment;
	if (car_diff == 0) //if there is no difference in cars then don't make an adjustment
	{
		adjustment = 0;
	}
	else //else take the log of the car difference and add to the green time
	{
		adjustment = log(car_diff);
	}

	cout << "Adjustment: " << adjustment << endl;

	if ((scoreAC - scoreBD) > 0) //adjust
	{
		cout << "adding to AC" << endl;
		// setNewTime wont go over 18 or under 2, this can be adjusted at light.cpp
		_lights.at(0).setNewTime(_lights.at(0).getTime() + adjustment);
		_lights.at(2).setNewTime(_lights.at(2).getTime() + adjustment);
		_lights.at(1).setNewTime(_lights.at(1).getTime() - adjustment);
		_lights.at(3).setNewTime(_lights.at(3).getTime() - adjustment);
	}
	else
	{
		cout << "adding to BD" << endl;
		_lights.at(1).setNewTime(_lights.at(1).getTime() + adjustment);
		_lights.at(3).setNewTime(_lights.at(3).getTime() + adjustment);
		_lights.at(0).setNewTime(_lights.at(0).getTime() - adjustment);
		_lights.at(2).setNewTime(_lights.at(2).getTime() - adjustment);
	}

	cout << "AC green time after Adjustment: " << _lights.at(0).getTime() << endl;
	cout << "BD green time after Adjustment: " << _lights.at(1).getTime() << endl;


}
