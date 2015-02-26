#include <stdio.h>
#include <string.h>

char rooms[10][20];
int counter=0;
void reserve();
void cancel();
void list();

int main()
{
	int i;
	int response;
	char reserveid[20];
	int howmanyrooms;

	for(i=0;i<10;i++)
	{	
		rooms[i][0]='\0';
	}
	while(1)
	{
		printf("MAX'S PALACE\n");
		printf("0: Make a reservation\n");
		printf("1: Cancel a reservation\n");
		printf("2: List all reserved rooms\n");
		scanf("%d",&response);

		switch(response)
		{
			case 0:
			   	printf("Please enter a name\n");
				scanf("%s",reserveid);
				printf("How many rooms would you like to reserve?\n");
				scanf("%d",&howmanyrooms);
				reserve(reserveid,howmanyrooms);
				break;
			case 1:
				printf("Please enter the name the reservation is under\n");
				scanf("%s",reserveid);
				cancel(reserveid);
				break;
			case 2:
				list();
				break;
			default:
				return 0;
		}
	}
}				

void reserve(char reserveid[],int howmanyrooms) 
{
	int i;
	int j;
	int k;
	int reservedrooms=0;
	int compare;
	int roomcounter=0;
	char *roomspointer=rooms[0];
	char *namecheckpointer=rooms[0];
	char *howmanyroomspointer=rooms[0];
	for(i=0;i<10;i++,roomspointer+=20)
	{
		if(*roomspointer=='\0')
		{
			for(j=0;j<10;j++,namecheckpointer+=20)
			{
				compare=strcmp(namecheckpointer,reserveid);
				if(compare==0)
				{
					printf("There is already a reservation under that name. Please enter a different one.\n");
					return;
				}
			}
			for(k=0;k<10;k++,howmanyroomspointer+=20)
				if(*howmanyroomspointer=='\0')
					roomcounter++;
			if(howmanyrooms>roomcounter)
			{
				printf("Unfortunately, there are only %d rooms available. You have %d rooms reserved.\n",roomcounter,roomcounter);
				howmanyrooms=roomcounter;
			}	
			while(reservedrooms<howmanyrooms)
			{	
				if(*roomspointer=='\0')
				{	
					strcpy(roomspointer,reserveid);
					reservedrooms++;
					counter ++;
				}
				roomspointer+=20;
			}	
			printf("Your room ID is:%s and you have %d rooms.\n",reserveid,howmanyrooms);
			i=10;
		}
	}	
	if(counter == 10)	
	printf("There are no more available rooms.\n");
}

void cancel(char reserveid[])
{
	int compare;
	int cancelcounter=0;
	int i;
	int j;
	int k;
	int roomscounter=0;
	char *roomspointer=rooms[0];
	char *gappointer=rooms[0];
	char *othernamespointer=rooms[0];
	if(counter==0)
		printf("The hotel is empty.\n");
	else
	{
		for(i=0;i<10;i++,roomspointer+=20)
		{
			if(strcmp(roomspointer,reserveid)==0)//this is where the names are actually deleted
			{
				*roomspointer='\0';
				counter--;
			}
			else
				cancelcounter++;
		}
		if(cancelcounter==10)
		{	
			printf("There are no rooms under that name.\n");
			return;
		}
		//here's the new stuff
		for(j=0;j<10;j++,gappointer+=20)//for finding the first open space
		{
			if(*gappointer=='\0')
				for(k=j,othernamespointer=gappointer;k<10;k++,othernamespointer+=20)
					if(*othernamespointer!='\0')//finds the first name after the open space
					{	
						strcpy(gappointer,othernamespointer);//copies
						*othernamespointer='\0';//deletes
						break;
					}
		}	
		printf("All of your rooms have been canceled.\n");	
	}
}	

void list()
{
	int i;
	char *roomspointer=rooms[0];
	if(counter==0)
		printf("All rooms are vacant.\n");
	else
	{
		printf("Reserved Rooms:\n");
		for(i=0;i<10;i++,roomspointer+=20)
		{
			if(*roomspointer!='\0')
			{	
				printf("Room %d is reserved under the name:",i+1);
				printf("%s\n",roomspointer);
			}
		}
	}	
}
	







