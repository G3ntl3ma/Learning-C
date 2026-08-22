#ifndef QUEUE_ADT
#define QUEUE_ADT

#include <stdbool.h>

typedef int Item;
typedef struct queueType *Queue;

Queue Create(void);
void Enqueue(Queue q, Item i);
Item Dequeue(Queue q);
Item FirstItem(Queue q);
Item LastItem(Queue q);
bool IsEmpty(Queue q);

#endif