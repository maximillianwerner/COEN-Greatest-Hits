/*
 * Max Werner
 * COEN 12 Project 4
 * 5/7/14
 *
 * This is the .c file for the ADT for deque implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

//Here are the declarations of a node and a deque.
struct node
{
	int data;
	struct node  *next;
	struct node  *prev;
};
struct deque
{
	int count;
	struct node *head;
};	

//This function will construct a deque with a dummy node head and initialize the counter.  It has a runtime ofO(1).
DEQUE *createDeque(void)
{
	DEQUE *dp;
	dp=malloc(sizeof(*dp));
	assert(dp!=NULL);
	dp->count=0;
	dp->head=malloc(sizeof(struct node));
	assert(dp->head!=NULL);
	//Here the head (dummy node) is set to point to itself.
	dp->head->next=dp->head;
	dp->head->prev=dp->head;
	return dp;
}

//This function will destroy the deque by looping through and freeing every node, then the deque itself.  Because of the loop, it has a runtime of O(n).
void destroyDeque(DEQUE *dp)
{
	assert(dp!=NULL);
	struct node *fred;
	struct node *freedom;

	freedom=dp->head;
	fred=dp->head->next;
	//This loop goes through the entire deque with two node pointers to make sure every node is freed.
	while(fred!=dp->head)
	{
		freedom=fred;
		fred=fred->next;
		free(freedom);
	}
	free(dp);
}	

//This function simply returns the number of nodes in the deque. It has a runtime of O(1).
int numItems(DEQUE *dp)
{
	assert(dp!=NULL);
	return dp->count;
}	

//This function will add a new node to the front(after the dummy node) of a deque. It has a runtime of O(1).
void addFirst(DEQUE *dp,int x)
{
	assert(dp!=NULL);
	struct node *new;
	new=malloc(sizeof(struct node));
	assert(new!=NULL);
	new->data=x;
	dp->count++;
	//Here the new node is set to have its previous and next pointers to the head and second node respectively.
	new->prev=dp->head;
	new->next=dp->head->next;
	//Here the head pointers are adjusted.
	dp->head->next->prev=new;
	dp->head->next=new;
}
//This function will add a new node to the back(before the dummy node) of a deque. It has a runtime of O(1).
void addLast(DEQUE *dp,int x)
{
	assert(dp!=NULL);
	struct node *new;
	new=malloc(sizeof(struct node));
	assert(new!=NULL);
	new->data=x;
	dp->count++;
	//Here the new node's next and prev pointers are set to the head and second to last node respectively.
	new->prev=dp->head->prev;
	new->next=dp->head;
	//Here the head pointers are adjusted.
	dp->head->prev->next=new;
	dp->head->prev=new;
}

//This function will free the first node in the deck.  It has a runtime of O(1).
int removeFirst(DEQUE *dp)
{
	assert(dp!=NULL);
	struct node *temp;
	struct node *np;
	int stored;

	temp=dp->head;
	dp->count--;
	np=temp->next;
	//Here the head pointer and second node pointers are adjusted to skip the first node.
	temp->next=np->next;
	np->next->prev=temp;
	stored=np->data;
	free(np);
	return stored;
}	
//This function will free the first node in the deck.  It has a runtime of O(1).
int removeLast(DEQUE *dp)
{
	assert(dp!=NULL);
	struct node *temp;
	struct node *np;
	int stored;

	temp=dp->head;
	dp->count--;
	np=temp->prev;
	//Here the head pointer and second to last node pointers are adjusted to skip the last node.
	temp->prev=np->prev;
	np->prev->next=temp;
	stored=np->data;
	free(np);
	return stored;
}

//This simple function returns the first real node in the deque.  It has a runtime of O(1).
int getFirst(DEQUE *dp)
{
	assert(dp!=NULL);
	return(dp->head->next->data);
}

//This simple function returns the last real node in the deque.  It has a runtime of O(1).
int getLast(DEQUE *dp)
{
	assert(dp!=NULL);
	return(dp->head->prev->data);
}
