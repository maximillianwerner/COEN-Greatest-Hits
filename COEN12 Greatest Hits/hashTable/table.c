/*
 * Max Werner
 * COEN 11 Friday Lab
 * 4/25/14
 *
 * This program will create a hash table for a set list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "set.h"

#define EMPTY 0
#define FILLED 1
#define DELETED 2

//This is the declaration of what a "set" is.
struct set
{
	int count;
	int length;
	char *flags;
	char **elts;
};

//This function will create a new set. It has a runtime of O(n).
SET *createSet(int maxElts)
{
	int i;
	SET *sp;

	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	sp->count=0;
	sp->length=maxElts;
	sp->elts=malloc((sizeof(char*))*maxElts);
	assert(sp->elts!=NULL);
	sp->flags=malloc(sizeof(char)*maxElts);
	assert(sp->flags!=NULL);
	//This loop  will initialize the flags array to empty.
	for(i=0;i<maxElts;i++)
		sp->flags[i]=EMPTY;
	return sp;
}

//This function will return the number of elements in a set.  It has a runtime of O(1). 
int numElements(SET *sp)
{
	assert(sp!=NULL);
	return sp->count;
}

//This function will destroy a set by freeing memory for the filled elements, the table of elements,the array of flags, and then the set itself in that order. It has a runtime of O(n).
void destroySet(SET *sp)
{
	int i;
	assert(sp!=NULL);
	//This loop only frees the filled locations in the array.
	for(i=0;i<sp->count;i++)
		if(sp->flags[i]==FILLED)
			free(sp->elts[i]);
	free(sp->flags);
	free(sp->elts);
	free(sp);
}

//This function will create a hash for a given string. It has a runtime of O(n) but a small n.
unsigned hashString(char *s)
{
	unsigned hash=0;

	while(*s != '\0')
		hash=31 * hash + *s ++;
	return hash;
}

//This is not one of the required functions, yet it is very usefull.  It uses hashing with linear probing to search for an element and return either the position, the first deleted location, or the first empty location. It has a best case runtime of O(1) and worst case of O(n).
int findElement(SET *sp,char *elt,bool *found)
{
	assert(sp!=NULL && elt!=NULL);	
	int i;
	int deleted_flag=0;
	int index_flag;
	unsigned hashlocation= hashString(elt);
	unsigned index;
	//This loop is for the linear probing.  It hashes the element and if there is a collision it linearly probes.
	for(i=0;i<sp->length;i++)
	{	
		index=(hashlocation+i)%sp->length;
		if(sp->flags[index]==FILLED)
		{  	
			if(strcmp(sp->elts[index],elt)==0)
			{	
		   		//The the element was found in the table and its location will be returned.
				*found=true;
		   		return index;
			}
		} 	
		else if(sp->flags[index]==EMPTY)
		{
			*found=false;
			//If there was a deleted location, it will return that instead of the first free one.
			if(deleted_flag==1)
				return index_flag;
			return index;
		}
		else if(sp->flags[index]==DELETED)
		{
			if(deleted_flag==0)
			{	
				//The first deleted location is remembered.
				index_flag=index;
				deleted_flag=1;
			}
		}	

	}
	return index;
}

//This function calls "findElement" and so long as the element is in the array, I will return true.  It has a best case runtime of O(1) and worst case of O(n).
bool hasElement(SET *sp,char *elt)
{
	bool found;
	assert(sp!=NULL && elt!=NULL);
	if(findElement(sp,elt,&found)!=-1)
		return found;
	else
		return found;
}

//This function adds an element so long as the element is not in the array. It will call "findElement" to do this check. After adding an element, it will change the flag to FILLED. It has a best case runtime of O(1) and worst case runtime of O(n).
bool addElement(SET *sp,char *elt)
{
	assert(sp!=NULL && elt!=NULL);
	bool found;
	int i;
	unsigned location=findElement(sp,elt,&found);
	if(sp->count==sp->length)
		return false;
	
	if(found==true)
		return false;
	//Intead of using strcpy, strdup is called because the array is using pointers.
	elt=strdup(elt);
	sp->elts[location]=elt;
	sp->flags[location]=FILLED;
	sp->count++;
	return true;
}

//This function removes a specified element so long as it is in the hash table. It calls "findElement" to do this. After freeing the element, it sets the flag of that position to "DELETED". It has a best case runtime of O(1) and worst case of O(n). 
bool removeElement(SET *sp,char *elt)
{
	assert(sp!=NULL && elt!=NULL);
	if(sp->count==0)
		return false;
	int position;
	int i;
	bool found;
	
	position=findElement(sp,elt,&found);
	if(found==false)
		return found;
	free(sp->elts[position]);
	sp->flags[position]=DELETED;
	sp->count--;
	return found;
}
