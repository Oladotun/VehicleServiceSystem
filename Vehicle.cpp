// Name: Oladotun Opasina
// Final Project Pt 2
// Vehicle.cpp

#include <iostream>
#include <iomanip> 
using namespace std;

#include "Vehicle.h" //include definition of class Vehicle from .h file

Vehicle::Vehicle() //default constructor
{
	
	currentTask = new Task();
	totalCostOfLabor = 0;
    totalCostOfParts = 0;
	
}
// default destructor
Vehicle::~Vehicle()
{
	if(currentTask != 0)
	{
		delete currentTask;
	}
	currentTask = 0;
	
}

// Set Id for particular Vehicle
void Vehicle::setId(const int &Id)
{
	this->uniqueId = Id ;

}
// Set Model for particular Vehicle
void Vehicle::setModel(const int &Model)
{
	this->modelYear = Model ;

}
// Set Mileage for particular Vehicle
void Vehicle::setMileage(const double &Mileage )
{
	this->mileage = Mileage;
}

// Set Model for particular Vehicle
void Vehicle::setColor(const string &Color)
{
	this->vehicleColor = Color;

}
void Vehicle::setVehicleType(const string &type)
{
	this->vehicleType = type;
}


void Vehicle::setTask()
{
	data_type newTask;
	char cont;

	do 
	{
		cin.ignore();
		cout << "Enter Task Name: ";
		getline(cin,newTask.name); // String input
		do{
			cout << "Enter Cost Of Labor: ";
			cin >> newTask.costOfLabor;
			cin.clear();	
		}while(newTask.costOfLabor < 0);
	
		cin.clear();
		do{
			cout << "Enter Cost Of Parts: ";
			cin >> newTask.costOfPart;
			cin.clear();
		}while(newTask.costOfPart < 0);

		currentTask->Insert(newTask);
		totalCostOfParts += newTask.costOfPart;
		totalCostOfLabor += newTask.costOfLabor;
		cout << "Enter another (Y/N): ";
		cin >> cont;
	}while(!(cont == 'N' || cont == 'n'));
}

// Return Id for particular Vehicle
int Vehicle::getId() const
{
	return this->uniqueId;

}

// getModel returns the Model year for the Vehicle
double Vehicle::getModel() const
{
	return this->modelYear;
}

// returns the mileage of the Vehicle
double Vehicle::getMileage() const
{
	return this->mileage;
}

// Initialize the members of the classs
void Vehicle::initializer() 
{
	int colorType;
	
	do
	{
		cout << "Enter Vehicle Model(2000-2014): ";
		cin >> modelYear;	
	}while(!(modelYear >= 2000 && modelYear <= 2014));


	do
	{
		cout << "Select Color of Car: " << endl;
		cout << "1. White 2. Black       3. Silver 4. Red         5. Gray " << endl;
		cout << "6. Blue  7. Beige/Brown 8. Green  9. Yellow/Gold 10. Other " << endl;
		cout << "Input number: ";
		cin >> colorType;

		switch(colorType)
		{
			case 1:
			vehicleColor = "White";
			break;
			case 2:
			vehicleColor =  "Black";
			break;
			case 3:
			vehicleColor = "Silver";
			break;
			case 4:
			vehicleColor = "Red";
			break;
			case 5:
			vehicleColor = "Gray";
			break;
			case 6:
			vehicleColor = "Blue";
			break;
			case 7:
			vehicleColor = "Beige/Brown";
			break;
			case 8:
			vehicleColor = "Green";
			break;
			case 9:
			vehicleColor = "Yellow/Gold";
			break;
			case 10:
			vehicleColor = "Other";
			break;			
			default:
			cout <<"Invalid Entry" << endl;
			vehicleColor = " ";

		}
	}while(vehicleColor == " ");

	do
	{
		cout << "Enter Mileage of Car: ";
		cin >> mileage;
	}while(mileage < 0);


}

// Display the Product Information 

void Vehicle::print() const
{  
	cout << "Vehicle Type: " << vehicleType << endl;
	cout << "Model Year: " << modelYear << endl;
	cout << "Color: " << vehicleColor << endl;
	cout << "Mileage: " << mileage << endl;   
  
}

void Vehicle::displayTask() const
{
	currentTask->Print();
	cout <<"Total Cost: " << totalCostOfLabor + totalCostOfParts << endl;

}

ostream &operator<<( ostream &output, const Vehicle &m )
{
	m.print();
	m.displayTask();
	
	return output;

} 
