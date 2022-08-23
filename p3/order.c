#include <stdio.h>
#include <stdlib.h>
#include "order.h"
#include "user_input.c"

int main(){
    int num1, num2, num3;
    char cOrder;
        
    readInts(&num1,&num2,&num3,&cOrder);
    if(cOrder == 'D'){
        descending3(&num1,&num2,&num3);
    }
    if(cOrder == 'A'){
        ascending3(&num1,&num2,&num3);
    }
    printf("Val1: %d, Val2: %d, Val3: %d\n", num1, num2, num3); 
    return 0;
}

static void ascending2(int* ptr1, int* ptr2){
    int temp = 0;
    if(*ptr1 <= *ptr2){
   
    }
    else{
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;     
    }

}

static void ascending3(int* ptr1, int* ptr2, int* ptr3){
    ascending2(ptr1,ptr2);
    ascending2(ptr1,ptr3);
    ascending2(ptr2,ptr3);
}

static void descending3(int* ptr1, int* ptr2, int* ptr3){
    ascending2(ptr3, ptr1);
    ascending2(ptr3, ptr2);
    ascending2(ptr2, ptr1);
}
