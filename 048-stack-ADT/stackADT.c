#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
    Item data;
    struct node *next;
};

struct stackType {
    struct node *top;
};

static void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack Create(void){
    Stack s = malloc(sizeof(struct stackType));
    if(s == NULL){
        terminate("Error in create: stack could not be created.\n");
    }
    s->top = NULL;
    return s;
}

void Destroy(Stack s){
    MakeEmpty(s);
    free(s);
}

void MakeEmpty(Stack s){
    while(!IsEmpty(s)){
        Pop(s);
    }
}

bool IsEmpty(Stack s){
    return s->top == NULL;
}

bool IsFull(Stack s){
    return false;
}

void Push(Stack s, Item i){
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
        terminate("Error in push: stack is full.\n");
    }

    newNode->data = i;
    newNode->next = s->top;
    s->top = newNode;
}

Item Pop(Stack s){
    struct node *oldTop;
    Item i;

    if(IsEmpty(s)){
        terminate("Error in pop: stack is empty.");
    }

    oldTop = s->top;
    i = oldTop->data;
    s->top = oldTop->next;
    free(oldTop);
    return i;
}