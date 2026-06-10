//Calculate a number of fibonacci numbers

#include <stdio.h>

int main(void){
    int n;
    printf("Enter amount of fibonacci numbers: ");
    scanf("%d", &n);

    int numbers[n];
    numbers[0] = 0;
    numbers[1] = 1;
    
    printf("The numbers are: ");
    for(int i = 2; i < n; i++){
        numbers[i] = numbers[i-1] + numbers[i-2];
        printf(" %d", numbers[i]);
    }

    printf("\n");

    return 0;
}