/*
 * By Max Werner and Abe Milian
 *
 * IMPLEMENTATION FILE: 
 *
 *This is a ll implementation of a deque 
 */

#include <iostream>
#include <cassert>
#include "deque.h"

using namespace std;

myDeque::myDeque()
{
	size=0;
}

void myDeque::clear()
{
	//loop through the entire queue and remove each node
	while(head!=NULL)
	{
		node *t=head;
		head=head->n;
		delete t;
	}
}

myDeque::~myDeque()
{
	clear();
}

myDeque::myDeque(const myDeque& other)
{
	//equate
	*this=other;
}

myDeque& myDeque::operator=(const myDeque &other)
{
	//self check
	if(this==&other)
		return *this;
	//deallocate
	clear();
	node *temp=other.head;
	//loop through the other list and copy each node by using the push function
	while(temp!=NULL)
	{
		pushBack(temp->d);
		temp=temp->n;
	}
	return *this;
}

double myDeque::popFront()
{
	assert(size!=0);
	double t=head->d;
	head=head->n;
	delete head->p;
	size--;
	return t;
}

double myDeque::popBack()
{
	assert(size!=0);
	double t=tail->d;
	tail=tail->p;
	delete tail->n;
	size--;
	return t;
}

void myDeque::pushFront(const double& x)
{
	//base case
	if(size==0)
		head=tail=new node(x);
	else
	{	
		node *t=new node(x,head);
		head->p=t;
		head=t;
	}	
	//this size incrementation covers every case
	size++;
}

void myDeque::pushBack(const double& x)
{
	//base case
	if(size==0)
		head=tail=new node(x);
	else
	{	
		node *t=new node(x,NULL,tail);
		tail->n=t;
		tail=t;
	}	
	//this size incrementation covers every case
	size++;
}

int myDeque::getSize()
{
	return size;
}

bool myDeque::isEmpty()
{
	if(size==0)
		return true;
	else
		return false;
}

void myDeque::printDeque()
{
	if(size == 0)
	{
		cout << "The deque is empty." <<endl;
		return;
	}	
	node *t=head;
		while(t!=NULL)
	{
		cout << t->d << ',';
		t=t->n;
	}
	cout << endl;
}
