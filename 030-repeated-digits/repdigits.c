// List how often digits appear in a given number

#include <stdio.h>

int main(void){
    int n, digit;
    int digits[9] = {0};
    printf("Enter the number: ");
    scanf("%d", &n);

    while(n > 0){
        digit = n % 10;
        digits[digit]++;
        n /= 10;
    }

    printf("Digit:      ");
    for(int i = 0; i <= 9; i++){
        printf(" %d", i);
    }

    printf("\nOccurences: ");
    for(int i = 0; i <= 9; i++){
        printf(" %d", digits[i]);
    }
    printf("\n");
    
    return 0;
}