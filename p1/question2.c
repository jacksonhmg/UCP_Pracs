#include <stdio.h>

int main(void) {
    int value1, value2;
    printf("Enter an integer! ");    
    scanf("%d", &value1);
    printf("Enter another integer to check if the first number is divisable by this one! ");
    scanf("%d", &value2);

    if(!(value1 % value2)){
        printf("divisable");
    }
    else{
        printf("not divisable");
    }
    return 0;
}
