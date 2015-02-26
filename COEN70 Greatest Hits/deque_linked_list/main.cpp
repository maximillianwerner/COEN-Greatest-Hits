/*
 * By Max Werner and Abe Milian
 *
 * IMPLEMENTATION FILE: 
 *
 *This is a ll implementation of a deque 
 */

#include <iostream>
#include "deque.h"

using namespace std;

int main()
{
	myDeque a;
	{
		myDeque b;
	}
	for(double i=0.5;i < 10.5; i++)
	{
		a.pushBack(i);
	}
	a.printDeque();
	double b=a.popFront(); 
	cout << b << endl;//should print 0.5
	return 1;
}	
