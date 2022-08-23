#include <stdio.h>
#include <stdlib.h>


/*int main(){
    int num1, num2, num3;
    char cOrder;

    readInts(&num1,&num2,&num3,&cOrder);
    return 0;
}*/

static void readInts(int* pNum1, int* pNum2, int* pNum3, char* pcOrder){
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", pNum1, pNum2, pNum3);    
    printf("Enter the ordering (Either A or D): ");
    scanf(" %c", pcOrder);
}
