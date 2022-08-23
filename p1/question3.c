#include <stdio.h>


int factorial(int n);


int main(void)
{
    int input, output;
    bool chck;
    chck = true;


    while(chck){
        /*int input,output;*/
        printf("Enter an integer to get its factorial! \n");
        scanf(" %d", &input);

	output = factorial(input);
	printf("Result: %d\n",output);
        
	chck = (input >= 0);
    }
    return 0;
}

int factorial(int n)
{
    int i;
    int result = 1;
    for(i=n;i>0;i--)
    {
        result = result*i;
	
    }
    return result;
}
