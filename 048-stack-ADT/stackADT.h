#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item;

typedef struct stackType *Stack;

Stack Create(void);
void Destroy(Stack s);
void MakeEmpty(Stack s);
bool IsEmpty(Stack s);
bool IsFull(Stack s);
void Push(Stack s, Item i);
Item Pop(Stack s);

#endif