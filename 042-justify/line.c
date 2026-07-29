#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int lineLen = 0;
int numWords = 0;
bool alternateLines = 0;

void ClearLine(void){
    line[0] = '\0';
    lineLen = 0;
    numWords = 0;
}

void AddWord(const char *word){
    if(numWords > 0){
        line[lineLen] = ' ';
        line[lineLen + 1] = '\0';
        lineLen++;
    }
    strcat(line, word);
    lineLen += strlen(word);
    numWords++;
}

int SpaceRemaining(void){
    return MAX_LINE_LEN - lineLen;
}

void WriteLine(void){
    int extraSpaces, spacesToInsert, i, j;
    extraSpaces = MAX_LINE_LEN - lineLen;
    for(i = 0; i < lineLen; i++){
        if(line[i] != ' '){
            putchar(line[i]);
        }
        else{
            if(alternateLines){
                spacesToInsert = extraSpaces / (numWords - 1);
            } else {
                spacesToInsert = extraSpaces / (numWords - 1);
                extraSpaces % (numWords - 1) != 0 ? spacesToInsert++ : spacesToInsert;
            }
            for(j = 1; j <= spacesToInsert + 1; j++){
                putchar(' ');
            }
            extraSpaces -= spacesToInsert;
            numWords--;
        }
    }
    putchar('\n');
}

void FlushLine(void){
    if (lineLen > 0){
        puts(line);
    }
}