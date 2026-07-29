#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LENGTH 20

int main(void){
    char word[MAX_WORD_LENGTH + 2];
    int wordLen;

    ClearLine();
    for(;;){
        wordLen = ReadWord(word, MAX_WORD_LENGTH+1);
        if(wordLen == 0){
            FlushLine();
            return 0;
        }
        if(wordLen + 1 > SpaceRemaining()){
            WriteLine();
            ClearLine();
        }
        AddWord(word);
    }
}