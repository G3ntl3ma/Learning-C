#include <stdio.h>
#include "word.h"

int ReadChar(void){
    int ch = getchar();
    if(ch == '\n' || ch == '\t'){
        return ' ';
    }
    return ch;
}

int ReadWord(char *word, int len){
    int ch, pos = 0;

    while((ch = ReadChar()) == ' ')
    ;
    while(ch != ' ' && ch != EOF){
        if(pos < len){
            word[pos++] = ch;
        }
        ch = ReadChar();
    }
    if(pos == len){
        word[pos - 1] = '*';
    }
    word[pos] = '\0';
    return pos;
}