// Author: Oladotun Opasina
// 
// Description: Task.h , header file for Task.cpp

 //Structure for the Task specification
#include <string>
typedef struct dummy_node_type{
	std::string name;
	double costOfLabor;
	double costOfPart;
	
} data_type;

class TaskNode
{
	friend class Task;
public:
	/* Constructor */
	TaskNode( const data_type &data ); 

	data_type Get_data() const;

private:
	data_type content;
	TaskNode *next;
};

class Task
{
public:
	/* Constructor & Destructor */
	Task(); 
	~Task();

	void Insert( const data_type &data );
	void Print() const;
private:
	/*Pointers for Queue linked list*/
	TaskNode *First_ptr;
	TaskNode *Last_ptr;
};
