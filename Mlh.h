// Oladotun Opasina
// Instructor: Dr. Yair Amir
// Final Project Part 1.


// Template Mlh class definition
#ifndef MLH_H
#define MLH_H
#include <iostream>
#include <iomanip>
 using namespace std;


#include "MlhNode.h" // MlhNode definition class
#include "ML_hash.h"

// Forward declaration
template< typename T > 
ostream &operator<<( ostream &output, const Mlh<T> &m);

template < typename T >
class Mlh
{

friend ostream &operator<<<T>( ostream &output, const Mlh<T> &m);

public:
	Mlh( ); // constructor
	~Mlh();
	bool Mlh_insert(const int &key, T *data);
	void Mlh_set_print_option(int key);
	T * Mlh_delete(const int &key);
	bool isEmpty() const;
	T *Mlh_get(const int &);
	void printWrapper(MlhNode<T> *traversePtr) const;
private:
 MlhNode< T > *stemPtr;
 int noOfLevel;
 int nodeCount;
 int totalNoOfObject;
 bool print_all;

};

//constructor 
template < typename T >
Mlh < T >::Mlh(): stemPtr(0), noOfLevel(0),nodeCount(0),totalNoOfObject(0)
{
	//Empty body
	
}
// Deconstructor
template < typename T >
Mlh < T >::~Mlh()
{
	if(stemPtr != 0) // delete only when the nodes are not empty
	delete stemPtr;	
}


// Insert a new key here
template < typename T >
bool Mlh<T>::Mlh_insert(const int &key, T *data)
{
	MlhNode<T> *traversePtr;
	MlhNode<T> *parentPtr = 0;
	int Level = 0;
	int nextLeafLevel;

	traversePtr = stemPtr;
	nodeCount++;

	while(traversePtr != 0)
	{

		if(traversePtr->Count > 5)
		{
			Level++;
			//noOfLevel++;
			nextLeafLevel = ML_hash(Level,key);
			if(traversePtr->element[nextLeafLevel].downPtr == 0)
			{
				parentPtr = traversePtr;
				nodeCount++;
			}
			traversePtr = traversePtr->element[nextLeafLevel].downPtr;
			nodeCount++; // Going down a level			
		}

		else // less than or equal to 5
		{
			//Search through the array
			for(int i= 1; i <= traversePtr->Count && traversePtr->element[i].key != -1; i++)
			{
				if(traversePtr->element[i].key == key) // Cannot Insert Duplicate
				{
					return false;
				}
			}
			if(traversePtr->Count == 5)
			{

				Level++;
				parentPtr = traversePtr;
				nodeCount++;

				// Expand the Stem to a Leaf
				for(int i= 1; i <= 5; i++)
				{
					nextLeafLevel = ML_hash(Level,parentPtr->element[i].key);
					traversePtr = parentPtr->element[nextLeafLevel].downPtr;
					nodeCount++;
					if(traversePtr == 0) // the node doesnt exist create a new one
					{
						traversePtr = new MlhNode<T>();
						traversePtr->upPtr = parentPtr;
						parentPtr->element[nextLeafLevel].downPtr = traversePtr;

					}	
					//Insert parent key and data to Child node				
					traversePtr->Count++;
					traversePtr->element[traversePtr->Count].key = parentPtr->element[i].key;
					traversePtr->element[traversePtr->Count].data = parentPtr->element[i].data;

				}
				nextLeafLevel = ML_hash(Level,key); //Find the next node below for hash Function
				noOfLevel = Level +1 ; //No of Levels include base level
				traversePtr = parentPtr->element[nextLeafLevel].downPtr; // adding to legal node below
				nodeCount++;
				//noOfLevel++;

			}
			else
				break;	// adding a new key & data		
		}			
		
}
		if(isEmpty()) // Set the stemPtr
		{
			stemPtr = new MlhNode<T>();
			traversePtr = stemPtr;
			nodeCount++;
			noOfLevel = Level +1 ;

		}
		else if(traversePtr == 0) // Create new node for a null position
		{
			traversePtr = new MlhNode<T>();
			traversePtr->upPtr = parentPtr;
			parentPtr->element[nextLeafLevel].downPtr = traversePtr;

		}
		// Insert new key and data		
		traversePtr->Count++;
		traversePtr->element[traversePtr->Count].key = key;
		traversePtr->element[traversePtr->Count].data = data;
		totalNoOfObject++;
		while(traversePtr->upPtr != 0) //Increment the parent Size
		{
			traversePtr->upPtr->Count++;
			traversePtr = traversePtr->upPtr;
			nodeCount++;
		}

		return true;

} // End of Mlh_Insert


template < typename T >
T* Mlh<T>::Mlh_delete(const int &key)
{
	MlhNode<T> *traversePtr;
	MlhNode<T> *parentPtr;
	T* currentData = 0;
	int Level = 0;
	int parentPositon;
	int nextLeafLevel; 
	bool keyPresent = false;


	traversePtr = stemPtr;
	nodeCount++;

	while(traversePtr != 0) 
	{
		if(traversePtr->Count > 5)
		{
			Level++;
			nextLeafLevel = ML_hash(Level,key);
			traversePtr = traversePtr->element[nextLeafLevel].downPtr;
			nodeCount++; 
		}
		else if(traversePtr->Count <= 5) // Being careful
		{
			for(int i= 1; i <= traversePtr->Count && traversePtr->element[i].key != -1; i++)
			{
				if(traversePtr->element[i].key == key)
				{

					keyPresent = true;
					currentData = traversePtr->element[i].data; // return data to be deleted in main

					for(int j = i; j + 1 <= traversePtr->Count && traversePtr->element[j+1].key != -1;j++)
					{
						traversePtr->element[j].key = traversePtr->element[j+1].key;
						traversePtr->element[j].data = traversePtr->element[j+1].data;
					}
					traversePtr->element[traversePtr->Count].key = -1;
					traversePtr->element[traversePtr->Count].data = 0;
					totalNoOfObject--;
					break; // break out for loop
				}
			}
			if(!keyPresent) // The key doesnt exist
				return 0;

			while(traversePtr != 0 && keyPresent)
			{
				traversePtr->Count--;
				//cout << " Size of count is: " << traversePtr->Count << endl;
				if(traversePtr->Count == 0) // only element in node deleted, delete that node
				{
				
					parentPtr = traversePtr->upPtr;
					nodeCount++;
					delete traversePtr;
					traversePtr = 0;
					traversePtr = parentPtr;
					nodeCount++;
					// set position below to null
					if(parentPtr != 0)
						parentPtr->element[nextLeafLevel].downPtr = 0;
					else 
					{
						stemPtr = 0; // We deleted the only element in the node
						noOfLevel = 0;


					}
				} 
				else if(traversePtr->Count == 5)
				{
					parentPtr = traversePtr;
					nodeCount++;
					parentPositon = 1;
				
					noOfLevel = Level - 1;					
					// Collapse a node
					for(int i = 1;  i <= 5; i++)
					{
						if(parentPtr->element[i].downPtr !=0)
						{
							traversePtr = parentPtr->element[i].downPtr;
							nodeCount++;
							//cout <<"Index "<< i <<"has " << traversePtr->Count<< endl;

							for(int j=1; j <= traversePtr->Count ; j++)
							{
								parentPtr->element[parentPositon].key = traversePtr->element[j].key; // Copy Children Key to parents Key
								parentPtr->element[parentPositon].data = traversePtr->element[j].data; // Copy Children Data to parents Data
								parentPositon++;
							}
								
								parentPtr->element[i].downPtr = 0;
								delete traversePtr; // Delete the Child Node
								traversePtr = 0;						
						}
					}
					traversePtr = parentPtr->upPtr;
					nodeCount++;
				}
				else 
				{
					traversePtr = traversePtr->upPtr;
					nodeCount++;
				}

					
			} // End of while loop
			return currentData;
		}// End of else statement

	} // End of while
	return 0; // the list is empty

} // End of Mlh_delete

// Return Data based on key
template < typename T >
T* Mlh<T>::Mlh_get(const int &key)
{
	MlhNode<T> *traversePtr;
	int Level = 0;
	int nextLeafLevel;

	traversePtr = stemPtr;
	nodeCount++;

	while(traversePtr !=  0)
	{
		if(traversePtr->Count > 5)
		{
			Level++;
			nextLeafLevel = ML_hash(Level,key);
			traversePtr = traversePtr->element[nextLeafLevel].downPtr;
			nodeCount++;
		}
		// Search for a node and return it data
		else
		{ 
			for(int i= 1; i <= traversePtr->Count && traversePtr->element[i].key != -1; i++)
			{
				if(traversePtr->element[i].key == key)
				{
					return traversePtr->element[i].data;
				}
			}
			return 0; // The data is not present
		}
	}
	return 0; // The data is not present

} // end of Mlh_get

// Overload << for mlh
template < typename T >
ostream &operator<<( ostream &output, const Mlh<T> &m )
{
	cout << "No Of Level " << m.noOfLevel << endl;
	cout << "No of Node pointing Done " << m.nodeCount << endl;
    cout << "Total No of Items in repository: " << m.totalNoOfObject << endl;

	if(m.stemPtr != 0 && m.print_all) // Print only when node is not empty 
	{
	 	m.printWrapper(m.stemPtr);
	}

	return output;

} 
// Calls the Recursive prints function for MLH
template < typename T >
void Mlh<T>::printWrapper(MlhNode<T> *traversePtr) const
{


	if(traversePtr->Count <=  5)
	{
		cout << "Number of keys in current node " << traversePtr->Count << endl;
		for(int i = 1; i <= traversePtr->Count; i++)
		{
			cout << " {" << traversePtr->element[i].key << "," << *(traversePtr->element[i].data) << "} ";
		}
			cout << endl;		
		
	}
	else
	{
		for(int i = 1; i <= 5; i++)
		{
			//cout << "Current Hash Node " << i << endl;
			if(traversePtr->element[i].downPtr != 0 )
			{
			  printWrapper(traversePtr->element[i].downPtr);
			}
		}
	}	

}

// Set option to print all data in Mlh or not
template< typename T >
void Mlh<T>::Mlh_set_print_option(int key)
{
	switch(key)
	{
		case 1: 
			print_all = true;
			break;
		default:
		print_all = false;
		
	}
}


// Returns if the Stem pointer is empty
template < typename T >
bool Mlh<T>::isEmpty() const
{
	return stemPtr==0;
}

#endif
