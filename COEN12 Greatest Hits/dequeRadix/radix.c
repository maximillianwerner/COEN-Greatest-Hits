/*
 * Max Werner
 * COEN 12 Project 4
 * 5/15/14
 *
 * This is the .c file for radix sorting that implements the ADT deque.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "deque.h"

#define r 10

int main()
{
	int i;
	int j;
	int k;
	int input;
	int max=0;
	int digits;
	int item;
	int divisor=1;
	DEQUE *main;
	DEQUE *bucket[r];

	//This loop initializes the array of deques.
	for(i=0;i<r;i++)
		bucket[i]=createDeque();
	main=createDeque();
	//This loop is for adding the elements into the main deque to be sorted.
	while(scanf("%d",&input)==1)
	{
		if(input<0)
		{	
			printf("Error. Negative number recieved.\n");
			return -1;
		}
		//This updates the max value.
		if(input>max)
			max=input;
		addLast(main,input);
	}
	//This equation shows how many significant digits will be evaluated.
	digits=ceil(log(max+1)/log(r));
	
	//Here is the main loop which keeps the sorting going until all of the significant digits have been sorted.
	for(j=0;j<digits;j++)
	{
		//Loop to read all values in main, remove them, and then add them to their respective bucket.
		while(numItems(main)!=0)
		{	
			item=removeFirst(main);
			//The equation in the brackets sorts the items into their respective bucket based on which sig fig is being evaluated.
			addLast(bucket[(item/divisor)%10],item);
		}
		//Loop for all the buckets to add their values back to main.
		for(k=0;k<r;k++)
		{
			//Loop for every item in the bucket.
			while(numItems(bucket[k])!=0)
			{	
				item=removeFirst(bucket[k]);
				addLast(main,item);
			}
		}
		divisor*=10;
	}
	//This loop reads the values from main and prints them in order.
	while(numItems(main)!=0)
	{
		item=removeFirst(main);
		printf("%d\n",item);
	}
	return 1;
}	

