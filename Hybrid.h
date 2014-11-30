
// Hybrid.h represent the header file for Hybrid.cpp
// Inherit from Class
// Class Cars is the base class 
#ifndef HYBRID_H
#define HYBRID_H

#include "Cars.h"
#include <iostream>
#include <iomanip> 
using namespace std;


class Hybrid : public Cars
{
friend ostream &operator<<( ostream &output, const Hybrid &m);
public:
    Hybrid();
    virtual void initializer();
    virtual void print() const;
    virtual ~Hybrid();

private:
     int motorPower;
     int motorUsage;
     double batteryCapacity; // In KWH
};

#endif