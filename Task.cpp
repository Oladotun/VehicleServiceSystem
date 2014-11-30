/* 
 * Tasks for a Vehicle
 *
 * The program implements a queue in its current form
 */

#include "Task.h"
#include <iostream>
#include <iomanip>

using namespace std;

/* TaskNode Constructor */
TaskNode::TaskNode( const data_type &data )
	: content( data ), next( NULL )
{
  // Empty body
}

// Returns the properties associated to a particular product
data_type TaskNode::Get_data() const
{
	return content;
}

// Constructor initializes the pointer for start/end of the cart
Task::Task()
{
	First_ptr = NULL;
	Last_ptr = NULL;
}
// Destructor deletes all the Task in the Cart
Task::~Task()
{
    TaskNode *pnode;

    while( First_ptr != NULL )
    {
	pnode = First_ptr;
	First_ptr = pnode->next;
	delete pnode;
	//cout << "Removing all products in Cart" << endl;
    }
    Last_ptr = NULL;
}

// Insert into the Queue by adding to the end
void Task::Insert( const data_type &data ) 
{

    TaskNode *pnode;

    pnode = new TaskNode( data );
    if( First_ptr == NULL)
    {
    First_ptr = pnode;
    Last_ptr = pnode;
    }
    else
    {
    Last_ptr->next = pnode;
    Last_ptr = pnode;
    
    }

}

// Print the Queue out as inserted
void Task::Print() const
{
    TaskNode *pnode;
    data_type data_out;

    cout << "Task Name\tLabor\tParts" << endl;
	
    pnode = First_ptr;

    while( pnode != NULL )
    {
	data_out = pnode->Get_data();
	cout << left <<setw(11) << data_out.name << "\t$" << data_out.costOfLabor << "\t$"<< data_out.costOfPart << endl;;
	pnode = pnode->next;
    }
    
}


