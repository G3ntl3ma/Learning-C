// reverse the digits of the number given

#include <stdio.h>

int main(void){
    int num, reverse_num;

    printf("Enter the number: ");
    scanf("%d", &num);

    for(; num>0; num/=10){
        reverse_num *= 10;
        reverse_num += num % 10;
    }
    printf("The reversed number is: %d\n", reverse_num);

    return 0;
}