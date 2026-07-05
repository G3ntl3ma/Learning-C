//Compare words to find the largest and smallest

#include <stdio.h>
#include <string.h>

#define STR_LEN 20

int main(void){
    char largest[STR_LEN], smallest[STR_LEN], current[STR_LEN];

    printf("Enter word: ");
    scanf("%20s", current);
    strcpy(smallest, current);
    strcpy(largest, current);

    while(strlen(current) != 4){
        printf("Enter word: ");
        scanf("%20s", current);

        if(strcmp(current, smallest) < 0){
            strcpy(smallest, current);
        } else if(strcmp(current, largest) > 0){
            strcpy(largest, current);
        }
    }

    printf("Smallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);
    return 0;
}