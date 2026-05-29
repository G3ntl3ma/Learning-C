// Print a table of squares

#include <stdio.h>

int main(void){
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Please enter the desired amount of entries: ");
    scanf("%d", &n);

    i = 1;
    printf("Number\tsquare\n");
    while(i <= n){
        printf("%d\t%d\n", i, i*i);
        i++;
    }

    return 0;
}