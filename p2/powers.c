#include <stdio.h>

int powers();

/*int main(void) {
    int check;
    int i;
    for(i = 0; i < 5; i++){
        check  = powers();
        printf("%d \n",check);
    }
    return 0;
}*/

int powers() {
    static int val = 2;
    val *= 2;
    #ifdef DEBUG
        printf("nice!");
    #endif
    return val;
}
