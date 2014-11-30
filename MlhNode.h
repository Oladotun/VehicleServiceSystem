// MlhNode.h : Node for each MLH
// Template MlhNode class definition
#ifndef MLHNODE_H
#define MLHNODE_H

#include <iostream>
#include <iomanip>
 using namespace std;

// forward declaration of class MLH required for
// friend declaration
template< typename T > class Mlh;

template < typename T >
class MlhNode
{
	friend class Mlh< T >; // make MLH a friend

public:
	MlhNode(); // constructor
	~MlhNode(); // Deconstructor

private:
	MlhNode< T > *upPtr; // Level above in Tree
	typedef struct nodeProperty
	{
		int key;
		T *data; // 
		MlhNode< T > *downPtr; // Level below in Tree
	} node;
	node element[6]; //Skip array position 0;
	int Count ; // Current number of data in the node

};

//constructor 
template < typename T >
MlhNode < T >::MlhNode()
{
	
	upPtr = 0;
	for(int i = 1; i < 6;i++)
	{
		element[i].key = -1; // set key values to -1
		element[i].downPtr= 0; //set element to NULL
	}
	Count = 0;
}

//Deconstructor 
template < typename T >
MlhNode < T >::~MlhNode()
{	  
   for(int i = 1; i <= 5; i++ )
   {
	if(element[i].downPtr != 0)
		delete element[i].downPtr;
   } 	
	
}
#endif
