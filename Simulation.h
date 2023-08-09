#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include "Vehicle.h"
#include "ArrayList.h"
#include "ArrayQueue.h"

using namespace std;
 
class Simulation
{

	public:
	//private:
		int current_time;
		ArrayList<Vehicle> *vehicles_list;
		ArrayQueue<Vehicle> *vehicles_queue;
		Vehicle current_transaction;

	public:
		Simulation(string file_name);
		~Simulation();
		bool done();
		void step();
		void print();
};
#include "Simulation.cpp"
#endif