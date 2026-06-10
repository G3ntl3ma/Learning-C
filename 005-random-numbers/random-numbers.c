//Print out the values of floats and int that have not been initialised

#include <stdio.h>

int main(void){
    int counter = 1;
    int a,b,c,d,e;
    float f,g,h,i,j;
    printf("Value %d: %d\n", counter, a);
    counter++;
    printf("Value %d: %d\n", counter, b);
    counter = counter + 1;
    printf("Value %d: %d\n", counter, c);
    counter++;
    printf("Value %d: %d\n", counter, d);
    counter++;
    printf("Value %d: %d\n", counter, e);
    counter++;
    printf("Value %d: %f\n", counter, f);
    counter++;
    printf("Value %d: %f\n", counter, g);
    counter++;
    printf("Value %d: %f\n", counter, h);
    counter++;
    printf("Value %d: %f\n", counter, i);
    counter++;
    printf("Value %d: %f\n", counter, j);
}