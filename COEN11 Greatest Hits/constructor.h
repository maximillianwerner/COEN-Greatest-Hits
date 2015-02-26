#ifdef CONSTRUCTOR_H_INCLUDED
#define CONSTRUCTOR_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NODE struct node
struct node
{
	int partysize;
	char name[20];
	NODE *next;
};
extern int counter;
extern NODE *head;
extern NODE *tail;

void reserve(char,int);
void seat();
void list();
void read(char*);
void write(char*);

#endif
