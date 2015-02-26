//HEADER
//FILE: keyed_bag.h

#include <iostream>
using namespace std;

class keyed_bag
{
	public:
		//Constructor
		keyed_bag(int=10);
		//Copy Constructor
        keyed_bag(const keyed_bag&);
		//Destructor
        ~keyed_bag();
        //assignment operator
		keyed_bag& operator =(const keyed_bag&);
		//output
        friend ostream& operator <<(ostream&, const keyed_bag&);
		//check if specified key is in the bag
        bool kContains(int);
        //insert an element and a key
		void insert(int, int);
        //increase capacity of the bag
		void increase();
        //remove a certain element by providing that element's key
		bool remove(int);
		int size_one(int);
	private:
		int cap;
		int size;
		int *p;
		int *k;
};
