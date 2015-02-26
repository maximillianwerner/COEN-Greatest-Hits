#include <stdio.h>
int main ()
{
        srand((int)time(NULL));
	int i;
	int x;
	int counter;
	counter = 0;
	for(i=0;i<10;i++){

		int number1;
        	number1 = rand()%13;
        

        	int number2;
        	number2 = rand()%13;
        
        	printf("%d x ",number1);
        	printf("%d =",number2);

		scanf("%d",&x);
		if(x == number1*number2)
			counter++;
	}
	printf("You got %d questions right!\n",counter);
        return 0;
}




