//HEADER
//FILE: llkeyed_bag.h

#include <iostream>
using namespace std;

class keyed_bag
{
	private:
		//Declare the node class
		class node
		{
			public:
				//have n point to NULL by default
                node(int x=int(), int y=int(), node* n=NULL)
                {
                    d=x;
                    k=y;
                    this->n=n;
                }
				int d;
                int k;
				node* n;
		};
		node* head;
		int size;
		//Removes all data from the LL
		void clear();
	public:
		//CTOR
		keyed_bag();
    
		//CCTOR
		keyed_bag(const keyed_bag&);
    
		//Assignment operator
		keyed_bag& operator=(const keyed_bag&);
		
        //DTOR
		~keyed_bag();
		
        //Add one new node at the end of the LL with data and a key
		void add(int,int);
    
        //Remove one occurence of x by providing it's key
		bool remove(int);
		
        //check if specified key is in the bag
    bool kContains(int);
    
        //Return size of the LL
		int getSize();
		
        //Return the instance count of x
		int count(int);
		
		void print_bag();
};