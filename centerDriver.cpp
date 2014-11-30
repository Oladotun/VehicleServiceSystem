// Name: Oladotun Opasina
// Final Project Pt 2
// centerDriver.cpp represents the Driver for the Vehicle center

#include <iostream>
using namespace std;

#include "Hybrid.h"
#include "Buses.h"
#include "Motorcycle.h"
#include "Vehicle.h"
#include "Mlh.h"
void displayMenu();
void vehicleMenu();
void TaskMenu();
void checkoutMenu();
Vehicle *newMotor;
Mlh<Vehicle> vehicleService;


int main()
{
	
	displayMenu();	

	
	// Cleaning up to avoid memory leak
	for (int i = 1; i <= 10000; i++)
	{
		newMotor = vehicleService.Mlh_get(i);
		if(newMotor != 0)
		{
			//newMotor->displayTask();
			delete newMotor;
			newMotor = 0;
		}

	}

}

// Display the Vehicle Center Menu
void displayMenu()
{
	int selected;
	do
	{
		
		cout << " Welcome to Vehicle Service Center" << endl;
		cout << "1. Add a new Vehicle " << endl;
		cout << "2. Add a new Task for Vehicles" << endl;
		cout << "3. Checkout Vehicle " << endl;
		cout << "4. Print Out all the Vehicles in Service " << endl;
		cout << "5. Quit " << endl;
		cout << "Input: " ;
		cin >> selected;

		switch(selected)
		{
			case 1:
			vehicleMenu();
			break;
			case 2:
			TaskMenu();
			break;
			case 3:
			checkoutMenu();
			break;
			case 4:
			vehicleService.Mlh_set_print_option(1); // Print all items in repository
			cout << vehicleService << endl; // Print Vehicle
			break;
			case 5:
			cout << "Have a nice day" << endl;
			
		}
	}while(selected!= 5);
}

// Represents the Menu for the different Vehicles
void vehicleMenu()
{
		int selected;
		do
		{
			cout << "Car Types We Service" << endl;
			cout << "1. Car 2. Hybrid Car 3. Buses 4. Motorcycle " << endl;
			cout << "Input: ";
			cin >> selected;

			switch(selected)
			{
				case 1:
				cout <<"Car selected" << endl;
				newMotor = new Cars();
				newMotor->setVehicleType("Car");
				break;
				case 2:
				cout <<"Hybrid Car selected" << endl;
				newMotor = new Hybrid();
				newMotor->setVehicleType("Hybrid Car");
				break;
				case 3:
				cout <<"Buses selected" << endl;
				newMotor = new Buses();
				newMotor->setVehicleType("Buses");
				break;
				case 4:
				cout <<"Motorcycle selected" << endl;
				newMotor = new Motorcycle();
				newMotor->setVehicleType("Motorcycle");
				break;
				default:
				cout << "Wrong Input" << endl;
				selected = 0;
			}
		}while(selected == 0);

		do
		{
			cout << "Enter Id between(1 and 10000): ";
			cin >> selected;
			
		}while(vehicleService.Mlh_get(selected) != 0 || !(selected >= 1 && selected <= 10000));

		newMotor->setId(selected);
		newMotor->initializer();
		newMotor->setTask();
		vehicleService.Mlh_insert(selected,newMotor);
		newMotor->print();

}
// Display Menu for a Task on a vehicle
void TaskMenu()
{
	int currentId;
	cout <<"Enter Vehicle Id: ";
	cin >> currentId;
	newMotor = vehicleService.Mlh_get(currentId);

	if( newMotor != 0)
	{
		newMotor->setTask();
		newMotor->displayTask();
		cout << "Task Added" << endl;
	}
	else
	{
		cout << "That Id is not present" << endl;
	}

}
// Display Menu used to checkout a present vehicle in center
void checkoutMenu()
{
	int currentId;
	cout <<"Enter Vehicle Id: ";
	cin >> currentId;
	newMotor = vehicleService.Mlh_delete(currentId);

	if( newMotor != 0)
	{
		cout << "Checking out: " << currentId << endl;
		newMotor->displayTask();
		delete newMotor;
		newMotor = 0;
	}
	else
	{
		cout << "That Id is not present" << endl;
	}

}