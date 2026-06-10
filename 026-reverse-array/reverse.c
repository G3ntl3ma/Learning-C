//Reverse the given numbers with the help of an array

#include <stdio.h>

#define N 10

int main(void){
    int nums[N], i;

    printf("Enter 10 Numbers to be reversed: ");

    for(i = 0; i < N; i++){
        scanf(" %d", &nums[i]);
    }

    printf("Numbers in reverse order:        ");
    for(i= N - 1; i>= 0; i--){
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}