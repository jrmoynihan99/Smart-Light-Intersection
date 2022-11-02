#include <unistd.h>
#include <iostream>
#include "light.h"
#include "intersection.h"
#include <time.h>
#include <math.h>

using namespace std;

void run_control_test_1();
void run_test_1();
int CYCLE_NUMBER = 0;
vector<int> CAR_WAITING_LIST;

int main(int argc, const char * argv[]) {

	//run_control_test_1();
	run_test_1();

	return 0;
}

void run_control_test_1()
{
	Intersection intersection1;
	int lightAtraffic, lightBtraffic, lightCtraffic, lightDtraffic;
	int sleepTime = 4, TIME = 0, periodTime = 30, numCycles = 1;
	while (TIME < 270)
	{
		intersection1._lights.at(0).addCarsWaiting(21);
		intersection1._lights.at(1).addCarsWaiting(14);
		intersection1._lights.at(2).addCarsWaiting(17);
		intersection1._lights.at(3).addCarsWaiting(11);

		//OPTION 1: run with a period of time, with the above code simulating the corresponding amount 
		//of cars at each light. In this case, there are 21 cars being pushed to light A every 30 seconds. 
		//We let 1 car through the light per second as an estimate, so for every second that a light is
		//green, it will let one car through. The way this works is we add cars to ewait at each light, 
		//and then we call "runCycles" with the amount of time that we want to simulate for. However,
		//the way it currently is doenst allow us to simulat efor a long time because the cars get added
		//out here as u can see on line 34. 

		/*intersection1.runCycles(periodTime);

		lightAtraffic = intersection1._lights.at(0).getCarsWaiting();
		cout << "Traffic at light A: after " << TIME << " seconds: " << lightAtraffic << endl;
		lightBtraffic = intersection1._lights.at(1).getCarsWaiting();
		cout << "Traffic at light B: after " << TIME << " seconds: " << lightBtraffic << endl;
		lightCtraffic = intersection1._lights.at(2).getCarsWaiting();
		cout << "Traffic at light C after " << TIME << " seconds: " << lightCtraffic << endl;
		lightDtraffic = intersection1._lights.at(3).getCarsWaiting();
		cout << "Traffic at light D: after " << TIME << " seconds: " << lightDtraffic << endl << endl;*/


		//OPTION 2: We run 1 cycle of traffic (lights A and C will run and then lights C and D will run)
		//When we return to this function, we can print out how many cars are currently waiting at each light
		//This option lets us see how many cars are waiting after each cycle where the other option simulates 
		//a custom amount of time given a certain number of cars. 
		intersection1.runCycle();

		lightAtraffic = intersection1._lights.at(0).getCarsWaiting();
		cout << "Traffic at light A after " << numCycles << " cycles: " << lightAtraffic << endl;
		lightBtraffic = intersection1._lights.at(1).getCarsWaiting();
		cout << "Traffic at light B after " << numCycles << " cycles: " << lightBtraffic << endl;
		lightCtraffic = intersection1._lights.at(2).getCarsWaiting();
		cout << "Traffic at light C after " << numCycles << " cycles: " << lightCtraffic << endl;
		lightDtraffic = intersection1._lights.at(3).getCarsWaiting();
		cout << "Traffic at light D after " << numCycles << " cycles: " << lightDtraffic << endl << endl;

		sleep(sleepTime);
		TIME += periodTime;
		numCycles++;
	}
}

void run_test_1()
{
	Intersection intersection1;
	int lightAtraffic, lightBtraffic, lightCtraffic, lightDtraffic;
	int sleepTime = 5, TIME = 0, periodTime = 10, numCycles = 1;
	while (TIME < 500)
	{
		//Patterned Data
		cout << "CYCLE NUMBER: " << CYCLE_NUMBER << endl;
		CYCLE_NUMBER++;
		srand((unsigned)time(NULL));
		int x = ceil(((float)rand() / RAND_MAX) * 17);
		if (x < 14)
		{
			x = 14;
		}
		intersection1._lights.at(0).addCarsWaiting(x);
		x = ceil(((float)rand() / RAND_MAX) * 7);
		if (x < 3)
		{
			x = 3;
		}
		intersection1._lights.at(1).addCarsWaiting(x);
		x = ceil(((float)rand() / RAND_MAX) * 17);
		if (x < 14)
		{
			x = 14;
		}
		intersection1._lights.at(2).addCarsWaiting(x);
		x = ceil(((float)rand() / RAND_MAX) * 7);
		if (x < 3)
		{
			x = 3;
		}
		intersection1._lights.at(3).addCarsWaiting(x);

		/*intersection1.runCycles(periodTime);

		lightAtraffic = intersection1._lights.at(0).getCarsWaiting();
		cout << "Traffic at light A: after " << TIME << " seconds: " << lightAtraffic << endl;
		lightBtraffic = intersection1._lights.at(1).getCarsWaiting();
		cout << "Traffic at light B: after " << TIME << " seconds: " << lightBtraffic << endl;
		lightCtraffic = intersection1._lights.at(2).getCarsWaiting();
		cout << "Traffic at light C after " << TIME << " seconds: " << lightCtraffic << endl;
		lightDtraffic = intersection1._lights.at(3).getCarsWaiting();
		cout << "Traffic at light D: after " << TIME << " seconds: " << lightDtraffic << endl << endl;*/

		//Algorithm/Adjustment
		intersection1.runCycle();


		lightAtraffic = intersection1._lights.at(0).getCarsWaiting();
		cout << "Traffic at light A after " << numCycles << " cycles: " << lightAtraffic << endl;
		lightBtraffic = intersection1._lights.at(1).getCarsWaiting();
		cout << "Traffic at light B after " << numCycles << " cycles: " << lightBtraffic << endl;
		lightCtraffic = intersection1._lights.at(2).getCarsWaiting();
		cout << "Traffic at light C after " << numCycles << " cycles: " << lightCtraffic << endl;
		lightDtraffic = intersection1._lights.at(3).getCarsWaiting();
		cout << "Traffic at light D after " << numCycles << " cycles: " << lightDtraffic << endl;

		int carsTotal = lightAtraffic + lightBtraffic + lightCtraffic + lightDtraffic;
		//cout << "Total cars waiting after " << numCycles << " cycles: " << carsTotal << endl << endl << endl;
		CAR_WAITING_LIST.push_back(carsTotal);//add total to list
		cout << "List of cars waiting: ";
		for (int i = 0; i < CAR_WAITING_LIST.size(); i++) {
			cout << CAR_WAITING_LIST.at(i) << ",";
		}
		cout << endl << endl << endl;

		sleep(sleepTime);
		TIME += periodTime;
		numCycles++;
	}
}
