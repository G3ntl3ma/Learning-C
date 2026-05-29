//Prints out 31 Days of a Calendar

#include <stdio.h>

int main(void){
    int day, start, maxDays;

    printf("Enter number of days in month: ");
    scanf("%d", &maxDays);
    printf("Enter starting day (1 = Mon, 7 = Sun): ");
    scanf("%d", &start);

    for(int i = 1; i < start; i++){
        printf("   ");
    }

    for(day = 1; day <= maxDays; day++, start++){
        printf("%2d ", day);
        if(start == 7){
            printf("\n");
            start = 0;
        }
    }

    printf("\n");

    return 0;
}