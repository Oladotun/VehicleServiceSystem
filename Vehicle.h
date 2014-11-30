// Class Vehicle is the base class

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Task.h" 
#include <iostream>
#include <iomanip> 
using namespace std;

static int maxNoOfTask = 10;
class Vehicle 
{
friend ostream &operator<<( ostream &output, const Vehicle &m);

public:
    Vehicle();
    void setId(const int &);
    void setModel(const int &);
    void setColor(const std::string &); 
    void setMileage(const double &);
    void setVehicleType(const string &type);
    void setTask();
    void displayTask() const;
    double getModel() const;
    double getMileage() const;
    int getId() const;
    virtual void initializer();
    virtual void print() const;
    virtual ~Vehicle();

protected:
    int uniqueId;
    int modelYear;
    std::string vehicleColor;
    std::string vehicleType; // Current Type of Vehicle
    double mileage;
    Task *currentTask; //A vehicle can have unlimited task performed on it
    double totalCostOfLabor;
    double totalCostOfParts;


};

#endif