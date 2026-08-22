#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    Item item;
    struct node *next;
};

struct queueType {
    struct node *first;
};

static void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue Create(void){
    Queue q = malloc(sizeof(struct queueType));
    q->first = NULL;
    return q;
}

void Enqueue(Queue q, Item i){
    struct node *newNode = malloc(sizeof(struct node));
    struct node *currentNode = q->first;

    newNode->item = i;
    newNode->next = NULL;

    if(currentNode == NULL){
        q->first = newNode;
        return;
    }

    for(; currentNode->next != NULL; currentNode = currentNode->next){
        ;
    }
    currentNode->next = newNode;
    return;
}

Item Dequeue(Queue q){
    struct node *currentNode = q->first;
    Item i;

    if(currentNode == NULL){
        terminate("Error: tried to dequeue empty queue.\n");
    }

    i = currentNode->item;
    q->first = currentNode->next;
    free(currentNode);
    return i;
}

bool IsEmpty(Queue q){
    return q->first == NULL;
}

Item FirstItem(Queue q){

    if(IsEmpty(q)){
        terminate("Error: tried to get first Item for empty queue.\n");
    }

    return q->first->item;
}

Item LastItem(Queue q){
    struct node *currentNode;

    if(IsEmpty(q)){
        terminate("Error: tried to get last item for empty queue.\n");
    }

    for(currentNode = q->first; currentNode->next != NULL; currentNode = currentNode->next){
        ;
    }
    return currentNode->item;
}