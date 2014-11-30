/* 
 * Checking random operation
 */

#include "random_op.h"
#include "Mlh.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Mlh<int> Node;
	Random_operation  *Rand_op;
	int *data;
	int seed;
	int range;
	int num_op;
	int num_get, num_delete, num_insert;
	char current_op;

	num_get    = 0;
    num_delete = 0;
    num_insert = 0;

	cout << "Enter Seed: ";
	cin >> seed;
	cout << "Enter Range: ";
	cin >> range;
	cout << "Enter Number of operations: ";
	cin >> num_op;

	Rand_op = new Random_operation(seed,range);

	for (int i = 0; i <= num_op; i++)
	{
		Rand_op->Randomize_next_op();
		current_op = Rand_op->Get_op();
		//cout << "Current Operation is: " << current_op << endl;

		switch(current_op)
		{
			case 'G':
            num_get++;
            Node.Mlh_get(Rand_op->Get_key());		
			break;

		    case 'I':
	        num_insert++;
			data = new int;
			*data = i;
		    if(Node.Mlh_insert(Rand_op->Get_key(),data) == false) // delete duplicate key's data
		    {
		    	delete data;
		    	data =0;
		    }	
			break;

		   case 'D':	    
	       num_delete++;
	       data = Node.Mlh_delete(Rand_op->Get_key());
		   if(data != 0)	
		   	{
		  		delete data;
		   		data = 0;
		   	}
			break;

		    default:
		    cout <<"\nError!!!, Illegal operation " << Rand_op->Get_op() << endl;
			return 0;
		}
		
		if( (i % (num_op/10)) == 0 )
		{
			cout << "Printing after " << i << " operations\n" ;
			if( range <= 100 )
			{
			     Node.Mlh_set_print_option( 1 );
			}
			else Node.Mlh_set_print_option( 0 );
			cout << Node << endl;
		}
			

	}
	delete Rand_op;
	
	// Clean the Mlh Data Structure to avoid memory leak
	for(int i = seed; i <= range; i++)
	{
		 data =  Node.Mlh_get(i);
		 if(data != 0)
		 {
		   delete data;
		   data = 0;
		 }
	}
}
