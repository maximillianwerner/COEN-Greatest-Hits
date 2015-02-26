/*By Max Werner and Abe Millian
 * 
 *INTERFACE and IMPLEMENTATION: binaryHeap.cpp
 *
 */
#include <iostream>
#include "binaryHeap.cpp"

using namespace std;

int main()
{
	binaryHeap a;
	a.push(5);
	a.push(1);
	a.push(10);
	a.push(200);
	a.push(2);
	a.push(11);
	cout << a.pop() << endl;
	cout << a.pop() << endl;
}
