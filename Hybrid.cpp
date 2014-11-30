// Name: Oladotun Opasina
// Final Project
// Hybrid.cpp


#include <iostream>
#include <iomanip> 
using namespace std;

#include "Hybrid.h" //include definition of class Hybrid from .h file

Hybrid::Hybrid():Cars() //default constructor
{
}

Hybrid::~Hybrid() //default destructor
{
}



void Hybrid::initializer() 
{
	Cars::initializer();
	do{
		cout << "Enter Hybrid's Motor Power: ";
		cin >> motorPower;
	}while(motorPower < 0);

	do
	{
		cout << "Enter Hybrid's Motor Total Hours Of Usage: ";
		cin >> motorUsage;
	}while(motorUsage < 0);

	do
	{
		cout << "Enter Battery Capacity : ";
		cin >> batteryCapacity;
	}while(batteryCapacity < 0);


}


void Hybrid::print() const
{
	Cars::print();
	cout << "Motor Power: " << motorPower << endl;
	cout << "Total Hours Of Usage: " << motorUsage << " Hours" << endl;
	cout << "Battery Capacity: " << batteryCapacity << " KWH" << endl;
}

ostream &operator<<( ostream &output, const Hybrid &m )
{
	m.print();
	m.displayTask();
	
	return output;

} 
