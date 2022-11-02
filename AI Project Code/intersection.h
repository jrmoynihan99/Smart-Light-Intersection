#ifndef intersection_h
#define intersection_h

#include "light.h"

using namespace std;

class Intersection
{
public:
	Intersection();
	Light getLight(int index);
	void runCycles(int timePeriod);
	void runCycle();
	void startAC(int timePeriod);
	void startBD(int timePeriod);
	void startA(int timePeriod);
	void startC(int timePeriod);
	void startB(int timePeriod);
	void startD(int timePeriod);
	void adjust();
	vector<Light> _lights;
private:
	int cycleCount;
};


#endif /* intersection_h */
