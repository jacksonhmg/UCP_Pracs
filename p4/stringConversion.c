#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    return 0;
}

void convert(char*[] charArr, int[] intArr, int length)
{
    int i;
    int x;
    for(i=0; i< length; i++)
    {
        x = atoi(charArr[i]);
        intArr[i] = x;
        printf("%d\n", intArr[i]);
    }

}
