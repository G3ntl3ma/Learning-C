// used for testing only. Everything in this file is only for testing

#include <stdio.h>

int main(void){
    int i, j;
    i = 3;
    j = 5;
    printf("%d\n", (i > j) - (i < j));

    return 0;
}