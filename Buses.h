
// Buses.h represent the header file for Buses.cpp
// Inherit from Class
// Class Vehicle is the base class 


#ifndef BUSES_H
#define BUSES_H

#include "Vehicle.h"
#include <iostream>
#include <iomanip> 
using namespace std;

class Buses : public Vehicle
{

friend ostream &operator<<( ostream &output, const Buses &m);

public:
    Buses();
    virtual void initializer();
    virtual void print() const;
    virtual ~Buses();

protected:
    int passengerCapacity;
};

#endif