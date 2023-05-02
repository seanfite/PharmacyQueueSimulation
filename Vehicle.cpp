#ifndef VEHICLE_CPP_
#define VEHICLE_CPP_

#include "Vehicle.h"

/*
Sean Fite
Data Structures
Assignment 5
*/

Vehicle::Vehicle(string name, int arrival_time, int processing_time, int start_time)    // default constructor
{
	if(arrival_time < 0)																// throw errors for invalid input
	{
		throw invalid_argument("the arrival time must be non-negative");
	}
	if(processing_time < 0)
	{
		throw invalid_argument("the processing time must be non-negative");
	}
	if(start_time < 0)
	{
		throw invalid_argument("the start time must be non-negative");
	}
    _name = name;								// set values from input file
    _arrival_time = arrival_time;
    _processing_time = processing_time;
    _start_time = start_time;
}

string Vehicle::get_name()				// get name
{
	return _name;
}

int Vehicle::get_arrival_time()			// get arrival time
{
	return _arrival_time;
}

int Vehicle::get_processing_time()		// get processing time
{
	return _processing_time;
}

int Vehicle::get_start_time()			// get start time
{
	return _start_time;
}
void Vehicle::set_start_time(int start_time)		// set start time
{
	_start_time = start_time;
}

bool Vehicle::operator< (const Vehicle& rhs)
{
	return this->_arrival_time < rhs._arrival_time;
}

ostream &operator<<(ostream &out, const Vehicle &that)  // output overloader
{
	out << "vehicle: { ";
	out << "name: " << that._name << ", ";
	out << "arrival_time: " << that._arrival_time << ", ";
	out << "processing_time: " << that._processing_time << ", ";
	out << "start_time: " << that._start_time << " }";
	return out;
}

#endif /* VEHICLE_CPP_ */