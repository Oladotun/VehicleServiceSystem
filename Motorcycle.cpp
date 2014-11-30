// Name: Oladotun Opasina
// Final Project
// Motorcycle.cpp

#include <iostream>
#include <iomanip> 
using namespace std;

#include "Motorcycle.h" //include definition of class Motorcycle from .h file

Motorcycle::Motorcycle():Vehicle() //default constructor
{
}

Motorcycle::~Motorcycle()
{
}




void Motorcycle::initializer() 
{
	Vehicle::initializer();
	cin.ignore();
	cout << "Enter Motorcycle's Engine Size: ";
	getline(cin,engineSize);

	do
	{
		cout << "Enter Motorcycle's Front Wheel Size: ";
		cin >> frontWheelSize;
	}while(frontWheelSize < 0);


	do
	{
		cout << "Enter Motorcycle's Back Wheel Size: ";
		cin >> backWheelSize;
	}while(backWheelSize < 0);


}

ostream &operator<<( ostream &output, const Motorcycle &m )
{
	m.print();
	m.displayTask();
	
	return output;

} 

void Motorcycle::print() const
{
	Vehicle::print();
	cout << "Engine Size: "<< engineSize << " cc" << endl;
	cout << "Front Wheel Size: " << frontWheelSize << " Inches" << endl;
	cout << "Back Wheel Size: " << backWheelSize << " Inches" << endl;
}