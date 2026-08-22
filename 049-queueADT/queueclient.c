// building a queue library and testing it
#include <stdio.h>
#include "queueADT.h"

int main(void){
    Queue q1, q2;
    int n;

    q1 = Create();
    q2 = Create();

    Enqueue(q1, 1);
    Enqueue(q1, 2);

    n = Dequeue(q1);
    printf("Dequeued %d from q1\n", n);
    Enqueue(q2, n);
    n = Dequeue(q1);
    printf("Dequeued %d from q1\n", n);
    Enqueue(q2, n);

    while(!IsEmpty(q2)){
        printf("Dequeued %d from q2\n", Dequeue(q2));
    }

    Enqueue(q2, 3);
    return 0;

}