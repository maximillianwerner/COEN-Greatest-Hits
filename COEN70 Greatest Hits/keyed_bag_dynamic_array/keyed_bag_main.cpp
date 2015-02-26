//MAIN
//FILE: keyed_bag_main.cpp

#include <iostream>
#include "keyed_bag.h"

using namespace std;

int main()
{
	keyed_bag a;
	keyed_bag b(100);
	a.insert(1,30);
	for(int i=0; i<20; i++)
	{
		a.insert(i,i);
	}
	cout << a.getSize() << endl;
	cout << a << endl;
	{
		keyed_bag x;
		x.insert(99,111111);
	}
	return 1;
}	
