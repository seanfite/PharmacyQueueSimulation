#include <iostream>
#include "Vehicle.h"
using namespace std;

void print(Vehicle &);

int main()
{
	cout << "create vehicle instance with invalid argument" << endl;
	try
	{
		Vehicle vehicle("varik", -1, 0, 0);
	}
	catch(const exception &e)
	{
		cout << "exception is caught: " << typeid(e).name() << endl;
		cout << "exception message: " << e.what() << endl;
	}

	return 0;
}

void print(Vehicle &vehicle)
{
	cout << "vehicle: name=" << vehicle._name;
	cout << ", arrival_time=" << vehicle._arrival_time;
	cout << ", processing_time=" << vehicle._processing_time;
	cout << ", start_time=" << vehicle._start_time;
}