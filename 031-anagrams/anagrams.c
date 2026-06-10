// check if 2 words are anagrams of each other

#include <stdio.h>
#include <ctype.h>

int main(void){
    int chars[26];
    char ch;

    printf("Type the first word: ");

    while((ch = getchar()) != '\n'){
        if(!isalpha(ch)){
            //skip
        } else {
            ch = tolower(ch);
            chars[ch - 'a']++;
        }
    }

    printf("Enter the second word: ");
    while((ch = getchar()) != '\n'){
        if(!isalpha(ch)){
            //skip
        } else {
            ch = tolower(ch);
            chars[ch - 'a']--;
        }
    }

    for(int i = 0; i < 26; i++){
        if(chars[i] != 0){
            printf("The words are not anagrams\n");
            return 0;
        }
    }
    printf("The words are anagrams\n");
    return 0;
}