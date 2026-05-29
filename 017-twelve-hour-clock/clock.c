// Convert from a 24-hour clock to a 12 hour clock

#include <stdio.h>

int main(void){
    int hours, minutes;

    printf("Enter 24 hour time: hh:mm : ");
    scanf("%d: %d", &hours, &minutes);

    if(hours >= 13){
        hours -=12;
    }

    printf("%d:%d\n", hours, minutes);

    return 0;
}