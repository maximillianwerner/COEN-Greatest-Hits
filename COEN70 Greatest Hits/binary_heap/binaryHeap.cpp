/*By Max Werner and Abe Millian
 * 
 *INTERFACE and IMPLEMENTATION: binaryHeap.cpp
 *
 */
#include <iostream>
#include <assert.h>
using namespace std;
 
class binaryHeap
{
	private:
		
		//the dynamic array in which the heap is stored
		int *array;
		
		//this is essentially the size variable because it is also the index of the last element in the array
		int last;
		int capacity;
		
		//find the index in the array of the left child given the parent's index
		int parent2leftchild(int i)
		{
			int lc = ((2 * i) + 1);
			return lc;
		}	
		
		//find the index of the parent to the child given
		int child2parent(int i)
		{
			int p = ((i - 1) / 2);
			return p;
		}	
		
		//these two functions are for keeping the heap order in case it was thrown off by an insertion
		void reheap_up(int i)
		{
			while(i > 0 && array[child2parent(i)] > array[i])
			{
				std::swap(array[child2parent(i)],array[i]);
				i=child2parent(i);
			}
		}
		
		void reheap_down()
		{
			int i = 0;
			while(parent2leftchild(i) <= last && array[i] > array[findSmallerChild(i)])
			{
				int sc = findSmallerChild(i);
				std::swap(array[i],array[sc]);
				i=sc;
			}
		}
			
		//find the smaller of the parent's two children
		int findSmallerChild(int i)
		{
			int lc = parent2leftchild(i);
			int rc = lc + 1;
			if(rc <= last && array[lc] > array[rc])
				return rc;
			else
				return lc;
		}	
	
	public:
		
		binaryHeap()
		{
			capacity = 20;
			last = -1;
			array = new int[20];
		}	
		
		//remove and return the root
		int pop()
		{
			int temp = array[0];
			array[0] = array[last--];
			reheap_down();
			return temp;
		}
			
		//add a new element to the heap
		void push(int x)
		{
			assert((last-1) != capacity);
			array[++last] = x;
			reheap_up(last);
		}	
};	
