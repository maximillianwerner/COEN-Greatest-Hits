/*
Max Werner
Lab 10, Friday
Prof. Figueira
3/14/13
*/

#include <constructor.h>

int main(int argc, char *argv[])
{
	int response;
	int seatsrequested;
	char enteredname[20];

	if(argc!=2)
	{	
		printf("The name of the file is missing\n");
		return 1;
	}	
	else
		read(argv[1]);	

	while(1)
	{
		printf("Welcome to AL's Beef!\n");
		printf("0: Make a table request\n");
		printf("1: Seat a party\n");
		printf("2: List all waiting parties\n");
		printf("3: Quit\n");
		scanf("%d",&response);
		
		switch(response)
		{
			case 0:
				printf("Please enter a name for the table.\n");
				scanf("%s",enteredname);
				printf("How many seats do you need?\n");
				scanf("%d",&seatsrequested);
				reserve(enteredname,seatsrequested);
				break;
			case 1:
				seat();
				break;
			case 2:
				list();
				break;
			default:
				write(argv[1]);
				return 0;
		}
	}
}
void reserve(char *enteredname,int seatsrequested)
{
	NODE *p;
	int compair;

	if(counter==10)
	{
		printf("We're sorry, but we are all booked up. Please comeback later.\n");
		return;
	}
	p=head;
	while(p!=NULL)
	{		
		compair=strcmp(p->name,enteredname);
		if(compair==0)
		{
			printf("There is already a table reserved under that name. Please enter a different one.\n");
			return;
		}
		p=p->next;
	}
	if(head==NULL && tail==NULL)
	{
		p=(NODE*)malloc(sizeof(NODE));
		if(p==NULL)
			return;
		strcpy(p->name,enteredname);
		p->partysize=seatsrequested;
		head=tail=p;
		p->next=NULL;
		counter++;
	}
	else
	{
		p=(NODE*)malloc(sizeof(NODE));
		if(p==NULL)
			return;
		strcpy(p->name,enteredname);
		p->partysize=seatsrequested;
		tail->next=p;
		tail=p;
		p->next=NULL;
		counter++;
	}	
			
	printf("Great, you are position %d.\n\n\n\n\n\n\n\n\n\n\n",counter);
}

void seat()
{
	NODE *p,*q;
	int tablesize;
	int cancelcounter=0;

	printf("What size table is available?\n");
	scanf("%d",&tablesize);
	if(counter==0)
	{
		printf("There are currently no table requests.\n");
		return;
	}
	p=q=head;
	while(p!=NULL)
	{
		if(p->partysize<=tablesize)
		{
			printf("%s party is ready to be seated.\n",p->name);
			break;
		}
		else
		{	
			cancelcounter++;
			q=p;
			p=p->next;
		}	
	}
	if(cancelcounter==counter)
	{
		printf("There are no parties for that size table\n");
		return;
	}
	if(head==tail)
		head=NULL;
	else if(p==head)
		head=head->next;
	else if(p==tail)
	{	
		q->next=NULL;
		tail=q;
	}	
	else 
		q->next=p->next;
	free(p);
	counter--;
	printf("The waiting list has been adjusted.\n\n\n\n\n\n\n\n\n\n\n\n");
}	

void list()
{
	NODE *p;
	if(counter==0)
	{
		printf("There are no table requests at this time\n");
		return;
	}
	p=head;
	while(p!=NULL)
	{
		printf("%s, party of %d.\n",p->name,p->partysize);
		p=p->next;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}

void read(char *filename)
{
	int partysize;
	char name[20];
	FILE *fp;
	fp = fopen(filename,"r");
	if(fp==NULL)
	{	
		printf("No file present\n");
		fclose(fp);
		return;
	}
	fseek(fp,30,SEEK_SET);
	while(fscanf(fp,"%s %d\n",name,&partysize)==2)
		reserve(name,partysize);
	fclose(fp);
}

void write(char *filename)
{
	FILE *fp;
	NODE *p;
	fp = fopen(filename,"w");
	if(fp==NULL)
	{
		printf("No file present");
		fclose(fp);
		return;
	}
	fprintf(fp,"Name  Group Size\n------------\n");
	p=head;
	while(p!=NULL)
	{
		fprintf(fp,"%s %d\n",p->name,p->partysize);
		p=p->next;
	}
	fclose(fp);
	printf("File has been written.\n");
}	
		





















