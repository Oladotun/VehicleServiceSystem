// Name: Oladotun Opasina
// Final Project
// Buses.cpp

#include <iostream>
#include <iomanip> 
using namespace std;

#include "Buses.h" //include definition of class Buses from .h file

Buses::Buses():Vehicle()//default constructor
{
}

Buses::~Buses() //default destructor
{
}


void Buses::initializer() 
{
	Vehicle::initializer();
	do
	{
		cout << "Enter Bus's Passenger Capacity: ";
		cin >> passengerCapacity;
	}while(passengerCapacity < 0);

}

void Buses::print() const
{
	Vehicle::print();
	cout << "Passenger Capacity " << passengerCapacity << endl;
}

ostream &operator<<( ostream &output, const Buses &m )
{
	m.print();
	m.displayTask();
	
	return output;

} 