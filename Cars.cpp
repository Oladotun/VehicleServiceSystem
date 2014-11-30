// Name: Oladotun Opasina
// Final Project
// Cars.cpp


#include <iostream>
#include <iomanip> 
using namespace std;

#include "Cars.h" //include definition of class Cars from .h file

Cars::Cars():Vehicle() //default constructor
{
}
Cars::~Cars()
{
}

void Cars::initializer() 
{
	int gasSelection;
	Vehicle::initializer();
	cin.ignore();
	cout << "Enter Engine Size: ";
	getline(cin,engineSize);
	do
	{
		cout << "Select gas type: " ;
		cout << "1. Premium 2. Regular 3. Midgrade: ";
		cin >> gasSelection;

		switch(gasSelection)
		{
			case 1:
			gasType = "Premium";
			break;
			case 2:
			gasType = "Regular";
			break;
			case 3:
			gasType = "Midgrade";
			break;
			
			default:
			cout <<"Invalid Entry" << endl;
			gasType = " ";

		}
	}while(gasType == " ");

	cout << "Enter Pollution Level: ";
	cin >> pollutantLevel;
}

void Cars::print() const
{
	Vehicle::print();
	cout << "Engine Size: " << engineSize << endl;
	cout << "Gas type: " << gasType << endl;
	cout << "Pollution Level: " << pollutantLevel << endl;

}

ostream &operator<<( ostream &output, const Cars &m )
{
	m.print();
	m.displayTask();
	return output;

} 