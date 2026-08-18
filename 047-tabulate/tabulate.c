//tabulate the values of trigonometric functions

#include <math.h>
#include <stdio.h>

void tabulate(double (*f) (double), double first, double last, double incr);

int main(void){
    double final, increment, initial;
    
    printf("Enter initial value: ");
    scanf("%lf", &initial);

    printf("Enter final value: ");
    scanf("%lf", &final);

    printf("Enter increment: ");
    scanf("%lf", &increment);

    printf("\nx\t\tcos(x)"
           "\n---------------------\n");
    tabulate(cos, initial, final, increment);

    printf("\nx\t\tsin(x)"
           "\n---------------------\n");
    tabulate(sin, initial, final, increment);

    printf("\nx\t\ttan(x)"
           "\n---------------------\n");
    tabulate(tan, initial, final, increment);

    return 0;
}

void tabulate(double (*f)(double), double first, double last, double incr){
    double x;
    int i, numIntervals;

    numIntervals = ceil((last - first) / incr);
    for(i = 0; i <= numIntervals; i++){
        x = first + i * incr;
        printf("%10.5f %10.5f\n", x, f(x));
    }
}