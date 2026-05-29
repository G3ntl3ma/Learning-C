// Calculate the dollar bills needed to make the payment

#include <stdio.h>

int main(void){
    int dollars, twentyDollarBills, tenDollarBills, fiveDollarBills, oneDollarBills;
    printf("Enter the amount of dollars you want: ");
    scanf("%d", &dollars);

    twentyDollarBills = dollars / 20;
    dollars = dollars -(twentyDollarBills * 20);
    tenDollarBills = dollars / 10;
    dollars = dollars -(tenDollarBills * 10);
    fiveDollarBills = dollars / 5;
    dollars = dollars -(fiveDollarBills * 5);
    oneDollarBills = dollars;

    printf("$20: %d\n", twentyDollarBills);
    printf("$10: %d\n", tenDollarBills);
    printf("$5: %d\n", fiveDollarBills);
    printf("$1: %d\n", oneDollarBills);

    return 0;
}