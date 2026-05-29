// Calculate the price of a shopping cart

#include <stdio.h>

int main(void){
    int itemNumber, day, month, year;
    float itemPrice;

    printf("Enter item Number: ");
    scanf("%d", &itemNumber);

    printf("Enter item Price: ");
    scanf("%f", &itemPrice);

    printf("Enter purchase date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Item\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%6.2f\t%d/%d/%d\n", itemNumber, itemPrice, day, month, year);

    return 0;
}