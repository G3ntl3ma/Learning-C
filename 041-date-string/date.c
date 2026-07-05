//Read a date and display it

#include <stdio.h>
#include <string.h>

int main(void){
    char *months[] = {"January", "February", "March", "April",
        "May", "June", "July", "August", "September", "October",
        "November", "December"};
    char ending[3];
    int day, month, year;

    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    switch(day){
        case 1: case 21: case 31: strcpy(ending, "st"); break;
        case 2: case 22:          strcpy(ending, "nd"); break;
        case 3: case 23:          strcpy(ending, "rd"); break;
        default:                  strcpy(ending, "th"); break;
    }
    printf("You entered the date: %d%s %s %d\n", day, ending, months[month - 1], year);
    return 0;
}