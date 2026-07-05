//read a sentence and print it out in the reverse order

#include <stdio.h>

int main(void){
    char sentence[100], ch, *p = &sentence[0];
    int length = 0;

    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n'){
        *p++ = ch;
    }

    printf("\n your sentence: ");
    while(p > &sentence[-1]){
        printf("%c", *p--);
    }

    printf("\n");
    return 0;
}