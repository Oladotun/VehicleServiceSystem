
// Cars.h represent the header file for Cars.cpp
// Inherit from Vehicle
#ifndef Cars_H
#define Cars_H

#include "Vehicle.h"
#include <iostream>
#include <iomanip> 
using namespace std;



class Cars : public Vehicle
{
friend ostream &operator<<( ostream &output, const Cars &m);

public:
    Cars();
    virtual void initializer();
    virtual void print() const;
    virtual ~Cars();

protected:
    std::string engineSize;
    std::string gasType;
    int pollutantLevel;
};

#endif