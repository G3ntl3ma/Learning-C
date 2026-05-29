//reduces a fraction to its lowest terms

#include <stdio.h>

int main(void){
    int numerator, denominator, lcd;

    printf("Enter the the fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    if(numerator < denominator){
        lcd = numerator;
    } else {
        lcd = denominator;
    }

    for(;lcd > 0; lcd--){
        if(numerator % lcd == 0 && denominator % lcd == 0){
            printf("In lowest terms: %d/%d\n", numerator / lcd, denominator / lcd);
            return 0;
        }
    }
    printf("Fraction already in lowest terms\n");
    return 0;
}