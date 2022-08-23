#include <stdio.h>
#include "macros.h"
#include "powers.h"

int main(void) {
    printf("val: %d\n", BETWEEN(1,3,2));
    printf("%d \n", powers());
    return 0;
}
     /*int bounds(int low, int high, int value);
    double bounds2(double low, double high, double value);
    int bounds3(char low, char high, char value);
    bounds(4,6,5);
    bounds2(3,2,1);
    char a;
    char b;
    char c;
    bounds3(a, c,  b);
    return 0;
}

int bounds(int low, int high, int value){
    int check;
    if((value>=low) && (value<=high)){
        check = TRUE;
    }
    else{
        check = FALSE;
    }
    printf("%d \n", check);
    return check;
}

double bounds2(double low, double high, double value){
    double check;
    if((value>=low) && (value<=high)){
        check = TRUE;
    }
    else{
        check = FALSE;
    }
    printf("%f \n", check);
    return check;
}

int bounds3(char low, char high, char value){
    int check; 
    if((value>=low) && (value<=high)){
        check = TRUE;
    }
    else{
        check = FALSE;
    }
    printf("%d \n", check);
    return check;
}*/
