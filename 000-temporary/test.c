// used for testing only. Everything in this file is temporary

#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void){
    char word[5];
    int i;

    strcpy(word, "abcd");
    i = 0;
    putchar(TOUPPER(word[++i]));
    printf("Current i: %d\n", i);
    return 0;
}

