
// Motorcycle.h represent the header file for Motorcycle.cpp
// Inherit from Class
// Class Vehicle is the base class 

#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
#include <iostream>
#include <iomanip> 
#include <string> 
using namespace std;
// Class Vehicle is the base class 

class Motorcycle : public Vehicle
{
	
friend ostream &operator<<( ostream &output, const Motorcycle &m);

public:
    Motorcycle();
    virtual void initializer();
    virtual void print() const;
    ~Motorcycle();

protected:
    string engineSize;
    int frontWheelSize;
    int backWheelSize;
};

#endif