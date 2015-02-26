//CLL_MAIN.CPP
#include <iostream>
#include "llkeyed_bag.h"
using namespace std;

int main()
{
	keyed_bag a;
	a.add(1,30);
	for(int i=0; i<20; i++)
	{
		a.add(i,i);
	}
    a.print_bag();
	cout << a.getSize() << endl;
	{
		keyed_bag x;
        x.add(7,7);
		x.add(99,111111);
        x.print_bag();
	}
	return 1;
}
