#include <stdio.h>
int main ()
{
	int number1;
	number1 = rand()%13;
	srand((int)time(NULL));

        int number2;
        number2 = rand()%13;
        srand((int)time(NULL));
	
	printf("Practice your multiplication!\n");
	printf("%d x ",number1);
	printf("%d",number2);

	return 0;
}
     

	
