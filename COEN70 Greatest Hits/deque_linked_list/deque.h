/* By Max Werner and Abe Milian
 *
 * HEADER FILE: deque.h
 *
 * This is a linked list implementation of a deque
 */

#include <iostream>

using namespace std;

class myDeque{
	private:
		//Node class declaration
		class node
		{
			public:
				double d;	
				node *n;
				node *p;
				//node ctor
				node(const double& x=double(),node *n=NULL, node *p=NULL)
				{	
					d=x;
					this->n=n;
					this->p=p;
				}	
		};
		node *head;
		node *tail;	
		int size;
	public:
		
		//ctor
		myDeque();
		
		//dtor
		~myDeque();
		
		void clear();
		
		//cctor
		myDeque(const myDeque&);
		
		//assignment operator
		myDeque& operator=(const myDeque&);
	    
		//removes and returns the first node
		double popFront();

		//remove and return the last node
		double popBack();
		
		//insert at the front
		void pushFront(const double&);
		
		//insert at the back of the list
		void pushBack(const double&);
		
		//return the size of the pqueue
		int getSize();

		//check to see if the pqueue is empty
		bool isEmpty();

		//print the pqueue from highest priority to lowest
		void printDeque();
};		
