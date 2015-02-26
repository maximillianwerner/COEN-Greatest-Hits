/*
 * Max Werner
 * COEN 11 Final
 * 3/21/14
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRIPLET struct triplet
struct triplet
{
	int array[3];
	TRIPLET *next;
};	
TRIPLET *head=NULL;
TRIPLET *tail=NULL;

void add();
void delete();
void show();
int countandshow();
void save();

int main(int argc, char *argv[])
{
	int input;

	while(1)
	{
		printf("Welcome to the Final Exam!\n");
		printf("0: Add a triplet\n");
		printf("1: Delete a triplet\n");
		printf("2: Show the list\n");
		printf("3: Count and show the number of triplets with zeros\n");
		printf("4: Save and quit\n");
		scanf("%d",&input);
		
		switch(input)
		{
			case 0:
				add();
				break;
			case 1:
				delete();
				break;
			case 2:
				show();
				break;
			case 3:
				countandshow();
				break;
			default:
				save(argv[1]);
				return 0;
		}
	}
}

void add()
{
	int i;
	int entered_number;
	TRIPLET *p;

	printf("Please add three numbers into your new triplet.\n");
	p=(TRIPLET*)malloc(sizeof(TRIPLET));
		for(i=0;i<3;i++)
		{
			scanf("%d",&entered_number);
			p->array[i]=entered_number;
		}
		

	if(head==NULL)
	{	
		head=tail=p;
		p->next=NULL;
	}	
	else
	{
		tail->next=p;
		tail=p;
		p->next=NULL;
	}
}

void delete()
{
	int i;
	int entered_number;
	TRIPLET *p,*q,*r;

	printf("Please enter the three numbers of the triplet you want to delete\n");
	r=(TRIPLET*)malloc(sizeof(TRIPLET));
	for(i=0;i<3;i++)
	{
		scanf("%d",&entered_number);
		r->array[i]=entered_number;
	}
	q=p=head;
	while(p!=NULL)
	{
		if((sizeof(p->array))==(sizeof(r->array)))
			break;
		q=p;
		p=p->next;
	}
	if(p==head)
		head=head->next;
	else if(p==tail)
		q->next=tail;
	else
		q->next=p->next;
	free(p);
	free(r);
}

void show()
{
	int i=1;
	int j;
	TRIPLET *p;
	
	p=head;
	if(p==NULL)
		printf("There are no triplets yet.\n");
	while(p!=NULL)
	{
		printf("Triplet %d:",i);
		for(j=0;j<3;j++)
		{
			printf("%d ",p->array[j]);
		}
		printf("\n");
		i++;
		p=p->next;
	}
}

int countandshow()
{
	int counter;
	TRIPLET *p;

	p=head;
	while(p!=NULL)
	{
		if(p->array[0]==0 || p->array[1]==0 || p->array[2]==0)
			counter ++;
		p=p->next;
	}
	printf("There are %d triplets with at least 1 zero.\n",counter);
	return 1;
}

void save(char *file)
{
	int i;
	int j;
	TRIPLET *p;
	FILE *fp;

	p=head;
	fp=fopen(file, "w");
	while(p!=NULL)
	{	
		fprintf(fp,"Triplet %d: ",j);
		for(i=0;i<3;i++)
		{	
			fprintf(fp,"%d ",p->array[i]);
		}
		fprintf(fp,"\n");
		p=p->next;
		j++;
	}
	fclose(fp);
}

