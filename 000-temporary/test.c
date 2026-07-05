// used for testing only. Everything in this file is temporary

#include <stdio.h>


int main(void){
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72, 88, 47, 11};
    int *low = &a[0], *high = &a[10], *middle;
    
    middle = low + (high - low) / 2;

    printf("The value is: %d\n", *middle);
    return 0;
}

