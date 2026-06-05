// measures the amount of characters of a given message

#include <stdio.h>

int main(void){
    int length = 0;

    printf("Enter you message: ");

    while(getchar() != '\n'){
        length++;
    }

    printf("Your message is %d character", length);
    if(length > 1){
        printf("s");
    }
    printf(" long\n");

    return 0;
}