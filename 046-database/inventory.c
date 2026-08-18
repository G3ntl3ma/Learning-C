//create a database with a linked list
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN];
    int onHand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *FindPart(int number);
void Insert(void);
void Search(void);
void Update(void);
void Print(void);
void Erase(void);

int main(void){
    char code;

    for(;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n'){
            ;
        }
        switch(code){
            case 'i': Insert();
                        break;
            case 's': Search();
                        break;
            case 'u': Update();
                        break;
            case 'p': Print();
                        break;
            case 'e': Erase();
                        break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct part *FindPart(int number){
    struct part *p;
    for(p = inventory;
        p != NULL && number > p->number;
        p = p->next){

        }
    if(p != NULL && number == p->number){
        return p;
    }
    return NULL;
}

void Insert(void){
    struct part *cur, *prev, *newNode;
    newNode = malloc(sizeof(struct part));
    if(newNode == NULL){
        printf("Database is full; cant add more parts\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &newNode->number);

    for(cur = inventory, prev = NULL;
        cur != NULL && newNode->number > cur->number;
        prev = cur, cur = cur->next){

        }
    if(cur != NULL && newNode->number == cur->number){
        printf("Part already exists\n");
        free(newNode);
        return;
    }

    printf("Enter part name: ");
    ReadLine(newNode-> name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &newNode->onHand);

    newNode->next = cur;
    if(prev == NULL){
        inventory = newNode;
    } else {
        prev->next = newNode;
    }
}

void Search(void){
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = FindPart(number);
    if(p != NULL){
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->onHand);
    } else {
        printf("Part not found\n");
    }
}

void Update(void){
    int number, change;
    struct part *p;

    printf("Enter part number");
    scanf("%d", &number);
    p = FindPart(number);
    if(p != NULL){
        printf("Enter change amount: ");
        scanf("%d", &change);
        p->onHand += change;
    } else {
        printf("Part not found\n");
    }
}

void Print(void){
    struct part *p;
    printf("Part number\tPart Name\t\t\tQuantity on hand\n");
    for(p = inventory; p != NULL; p = p->next){
        printf("%11d%-25s%11d\n", p->number, p->name, p->onHand);
    }
}

void Erase(void){
    struct part *prev, *cur, *next;
    int num;

    printf("Enter part number that needs to be erased: ");
    scanf("%d", &num);
    for(cur = inventory, prev = NULL;
        cur != NULL && num != cur->number;
        prev = cur, cur = cur->next){

        }

    if(cur == NULL){
        printf("Number has not been found\n");
    } else {
        if(prev == NULL){
            inventory = cur->next;
        } else {
            next = cur->next;
            prev->next = next;
        }
        free(cur);
        printf("Part number %d has been succesfully erased\n", num);
    }
}