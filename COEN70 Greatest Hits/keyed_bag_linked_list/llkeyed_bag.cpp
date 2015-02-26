//CLL_BAG.CPP
#include <iostream>
#include<cstdlib>
#include "llkeyed_bag.h"
using namespace std;

//CTOR
keyed_bag::keyed_bag()
{
	head=new node();
	size=0;
}

//CCTOP
keyed_bag::keyed_bag(const keyed_bag& other)
{
	head=new node();
	*this=other;
}

//Assignment operator
keyed_bag& keyed_bag::operator=(const keyed_bag& other)
{
	//self check
	if(this==&other)
		return *this;
	//clear
	clear();
	head=new node();
	node *temp=other.head->n;
	//copy
	while(temp!=NULL)
	{
		add(temp->d,temp->k);
		temp=temp->n;
	}
	return *this;
}

void keyed_bag::clear()
{
	node *temp;
	//loops through the ll and deletes the nodes
	while(head!=NULL)
	{
		temp=head;
		head=head->n;
		delete temp;
	}
	size=0;
}

keyed_bag::~keyed_bag()
{
	clear();
}

void keyed_bag::add(int x,int key)
{
	if(kContains(key))
        return;
    node *t=new node(x,key,head->n);
    head->n=t;
    size++;
}

bool keyed_bag::remove(int key)
{
    node *p=head->n;
	node *t;
	//search for the node with the target data
	while(p!=NULL)
	{
		//look ahead to see if at the end of the list and check if next node has the target
		if(p->n!=NULL && p->n->k==key)
		{
			t=p->n;
			p->n=t->n;
			delete t;
			return true;
		}
		p=p->n;
	}
	return false;
}	

bool keyed_bag::kContains(int key)
{
    node *p=head->n;
    while(p!=NULL)
    {
        if(p->k==key)
            return true;
        p=p->n;
    }
    return false;
}

int keyed_bag::getSize()
{
	return size;
}

int keyed_bag::count(int x)
{
	int counter=0;
	node *p=head->n;
	//loop through the list and count the number of occurences of the target
	while(p!=NULL)
	{
		if(p->d == x)
			counter++;
		p=p->n;
	}
	return counter;
}

void keyed_bag::print_bag()
{
	int counter=0;
    node *p=head->n;
	cout << "Internal node data: (<data> , <key>)" << endl;
    //loop through the list and print every element abd then a comma after it
    while(p!=NULL)
	{
		cout << "Node" << counter << "(" << p->d << ',' << p->k << ")" << ',';
		p=p->n;
        counter ++;
	}
	cout << endl;
}