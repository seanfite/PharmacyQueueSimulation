#ifndef SIMULATION_CPP_
#define SIMULATION_CPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vehicle.h"
#include "ArrayList.h"
#include "ArrayQueue.h"
#include "Simulation.h"
using namespace std;

/*
Sean Fite
Data Structures
Assignment 5
*/

Simulation::Simulation(string file_name) : vehicles_list(nullptr), vehicles_queue(nullptr), current_time(0)
{																	// defualt constructor to read in file
	fstream newfile;
	newfile.open(file_name, ios::in);
	vehicles_queue = new ArrayQueue<Vehicle>();
	if (!newfile.is_open())
	{
		cout << "Bad open on file " << file_name << endl;
		exit(1);
	}
	vehicles_list = new ArrayList<Vehicle>();
	string tp;
	while (getline(newfile, tp))									// assign file input values to list
	{
		stringstream ss(tp);
		string name;
		int arrivalTime;
		int processingTime;
		ss >> name;
		ss >> arrivalTime;
		ss >> processingTime;
		Vehicle vehicle1(name, arrivalTime, processingTime, 0);
		vehicles_list->insert(vehicle1);
	}
	newfile.close();
	vehicles_list->sort();									// sort list
}

Simulation::~Simulation()									// destructor
{
	vehicles_queue = nullptr;
	vehicles_list = nullptr;
	current_time = 0;
	current_transaction.get_name() = "";
}

bool Simulation::done()										// if simulation is done return true
{
	return vehicles_list->size() == 0 && vehicles_queue->_size == 0 && current_transaction.get_name() == "";
}

void Simulation::step()										// step through simulation
{	
	if(current_transaction.get_name() == "" && current_time == vehicles_list->get(0).get_arrival_time())
	{														// set current transaction as first value in sorted list
		current_transaction = vehicles_list->get(0);
		current_transaction.set_start_time(current_time);
		return;
	}
	for(int i = 0; i < vehicles_list->size(); i++)			// iterate through list to enqueue or set start time of first transaction
	{
		if(vehicles_list->get(i).get_arrival_time() - 1 == current_time && current_transaction.get_name() == "")
		{
			current_transaction = vehicles_list->get(0);
			current_transaction.set_start_time(current_time);
			current_time++;
			return;
		}
		if(vehicles_list->get(i).get_arrival_time() - 1 == current_time)
		{
			vehicles_queue->enqueue(vehicles_list->get(i));
		}
	}
	if(current_transaction.get_processing_time() + current_transaction.get_start_time() == current_time + 1)
	{														// dequeue queue and set new current transaction
		if(vehicles_queue->is_empty())
		{
			vehicles_list->removeAt(0);
			current_transaction._name = "";
		}
		else
		{
			vehicles_queue->dequeue();
			vehicles_list->removeAt(0);
			current_transaction = vehicles_list->get(0);
			current_transaction.set_start_time(current_time + 1);
		}
	}
	current_time++;
}

void Simulation::print()								// print output
{
	cout << "Time: " << current_time << endl;
	cout << "Queue:" << endl;
	if (vehicles_queue == nullptr || vehicles_queue->is_empty())
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		for (int i = 1; i <= vehicles_queue->_size; i++)
		{
			cout << vehicles_list->get(i) << endl;
		}
	}
	cout << "Transaction:" << endl;
	if (current_transaction.get_name() != "")
	{
		cout << current_transaction << endl;
	}
	else
	{
		cout << "EMPTY" << endl;
	}
}

#endif /* SIMULATION_CPP_ */