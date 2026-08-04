#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

typedef struct {
    int number;
    char name[NAME_LEN + 1];
    int onHand;
    float price;
} part;

int FindPart(int number, part inventory[], int numParts);
void Insert(part inventory[], int numParts);
void Search(part inventory[], int numParts);
void Update(part inventory[], int numParts);
void ChangePrice(part inventory[], int numeParts);
void Print(part inventory[], int numParts);


int main(void){
    part inventory[MAX_PARTS];
    
    int numParts = 0;

    char code;
    for(;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n')
            ;
        switch(code){
            case 'i': Insert(inventory, numParts);
                        numParts++;
                        break;
            case 's': Search(inventory, numParts);
                        break;
            case 'u': Update(inventory, numParts);
                        break;
            case 'p': Print(inventory, numParts);
                        break;
            case 'c': ChangePrice(inventory, numParts);
                        break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int FindPart(int number, part inventory[], int numParts){
    int i;

    for(i = 0; i < numParts; i++){
        if(inventory[i].number == number){
            return i;
        }
    }
    return -1;
}

void Insert(part inventory[], int numParts){
    int partNumber;
    if(numParts == MAX_PARTS){
        printf("Database is full; Cannot add more parts\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &partNumber);

    if(FindPart(partNumber, inventory, numParts) >= 0){
        printf("Part already exists\n");
        return;
    }

    inventory[numParts].number = partNumber;
    printf("Enter part name: ");
    ReadLine(inventory[numParts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[numParts].onHand);
    printf("Enter price of part: ");
    scanf("%f", &inventory[numParts].price);
}

void Search(part inventory[], int numParts){
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = FindPart(number, inventory, numParts);
    if (i >= 0){
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].onHand);
    } else {
        printf("Part not found\n");
    }
}

void Update(part inventory[], int numParts){
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = FindPart(number, inventory, numParts);
    if(i >= 0){
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].onHand += change;
    } else {
        printf("Part not found.\n");
    }
}


void ChangePrice(part inventory[], int numParts){
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = FindPart(number, inventory, numParts);
    if(i >= 0){
        printf("Enter new Price: ");
        scanf("%d", &change);
        inventory[i].onHand = change;
    } else {
        printf("Part not found.\n");
    }
}


void Print(part inventory[], int numParts){
    int i, j, nextPart = -1, previousPart = -1;
    
    printf("Part Number Part Name             "
        "Quantity on Hand       Price\n");

    for(i = 0; i < numParts; i++){
        for(j = 0; j < numParts; j++){
            if(previousPart == -1){
                if(nextPart == -1 || inventory[nextPart].number > inventory[j].number){
                    nextPart = j;
                }
            } else if(nextPart == -1 && inventory[j].number > inventory[previousPart].number){
                nextPart = j;
            } else if( inventory[previousPart].number < inventory[j].number &&
                    inventory[nextPart].number > inventory[j].number){
                    nextPart = j;
                 }
        }

        printf("%-12d%-22s%-23d%f\n", inventory[nextPart].number, inventory[nextPart].name, inventory[nextPart].onHand, inventory[nextPart].price);

        previousPart = nextPart;
        nextPart = -1;
    }
}