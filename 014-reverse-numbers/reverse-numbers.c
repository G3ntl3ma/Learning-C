// reverse the numbers of the number written in the input

#include <stdio.h>

int main(void){
    int input, d1, d2, d3;
    printf("Enter the number: ");
    scanf("%d", &input);
    d1 = input / 100;
    input -= d1 * 100;
    d2 = input / 10;
    d3 = input % 10;

    printf("The reverse is: %d%d%d\n", d3, d2, d1);
}