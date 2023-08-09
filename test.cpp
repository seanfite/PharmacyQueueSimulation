#include <iostream>
#include "Simulation.h"
//#include "Simulation.cpp"
using namespace std;

int main()
{
	Simulation *simulation = new Simulation("data_01.txt");
	while (!simulation->done())
	{
		simulation->step();
		simulation->print();
		cout << "====================================================" << endl;
	}

	delete simulation; 
	return 0;
}