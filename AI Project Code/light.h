#ifndef light_h
#define light_h

#include <vector>
#include <map>
#include <string>

using namespace std;

class Light
{
public:
	Light();
	void setNewTime(/*string color,*/ double time);
	void setState(string color);
	string getState();
	void addCarsWaiting(int num);
	void letCarThrough();
	double getTime(/*string color*/);
	int getCarsWaiting();
	int score;
private:
	//map<string, int> _cyclePeriods;
	//double greenTimeRemaining;
	double greenTime;
	int TimeLeft;
	int _carsWaiting;
	string state;
	int currHour;

};

#endif /* light_h */
