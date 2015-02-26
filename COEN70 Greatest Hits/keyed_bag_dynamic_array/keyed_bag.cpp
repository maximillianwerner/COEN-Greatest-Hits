//IMPLEMENTATION
//FILE: keyed_bag.h

#include <iostream>
#include "keyed_bag.h"
using namespace std;

//ctor
keyed_bag::keyed_bag(int c)
{
	cap=c;
	size=0;
	p=new int[c];
	k=new int[c];
}
//cctop
keyed_bag::keyed_bag(const keyed_bag& other)
{
	//initialize before equating
    this->p=NULL;
	this->k=NULL;
	*this=other;
}	

//dtor
keyed_bag::~keyed_bag()
{
	//make sure the arrays are not empty
    if(p!=NULL || k!=NULL)
	{	
		delete[]p;
		delete[]k;
	}	
}

//assignment
keyed_bag& keyed_bag::operator =(const keyed_bag& other)
{
	//self check
    if(this==&other)
		return *this;
	//clear
    if(this->p != NULL || this->k != NULL)
	{	
		delete[] this->p;
		delete[] this->k;
	}
    //copy
	this->p=new int[other.cap];
	this->k=new int[other.cap];
	this->cap=other.cap;
	this->size=other.size;
	std::copy(other.p,other.p+other.size,this->p);
	std::copy(other.k,other.k+other.size,this->k);
	return *this;
}

//out
ostream& operator <<(ostream& out, const keyed_bag& b)
{
	//loop through all elts in the bag and print
    for(int i=0;i<b.size;i++)
		out << b.p[i] << ',';
	return out;
}

bool keyed_bag::kContains(int key)
{
	//sequential serch for key
    for(int i=0; i<size; i++)
	{
		if(k[i]==key)
			return true;
	}
	return false;
}	

void keyed_bag::insert(int x, int key)
{
	//incr cap if size is bigger
    if(this->size >= cap)
		increase();
	if(this->kContains(key))
		return;
	p[size]=x;
    //only incr size once
	k[size++]=key;
}

void keyed_bag::increase()
{
	//make one temp with new cap per array
    int *temp=new int[cap*2];
	int *temp2=new int[cap*2];
	std::copy(p,p+size,temp);
	std::copy(k,k+size,temp2);
	delete[]p;
	delete[]k;
	p=temp;
	k=temp2;
	cap=cap*2;
}

bool keyed_bag::remove(int key)
{
	//search for key and delete both elt and key if found
    for(int i=0;i<size;i++)
	{
		if(k[i]==key)
		{
			k[i]=k[size-1];
			p[i]=p[size-1];
			size--;
			return true;
		}
	}
	return false;
}	

int keyed_bag::getSize(){return size;}
