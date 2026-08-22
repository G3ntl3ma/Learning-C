// building a stack and testing it
#include <stdio.h>
#include "stackADT.h"

int main(void){
    Stack s1, s2;
    int n;

    s1 = Create();
    s2 = Create();

    Push(s1, 1);
    Push(s1, 2);

    n = Pop(s1);
    printf("Popped %d from s1\n", n);
    Push(s2, n);
    n = Pop(s1);
    printf("Popped %d from s1\n", n);
    Push(s2, n);

    Destroy(s1);

    while(!IsEmpty(s2)){
        printf("Popped %d from s2\n", Pop(s2));
    }

    Push(s2, 3);
    MakeEmpty(s2);
    if(IsEmpty(s2)){
        printf("s2 is empty\n");
    } else {
        printf("s2 is not empty\n");
    }

    Destroy(s2);

    return 0;

}