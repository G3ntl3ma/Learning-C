//use malloc to create a more flexible reminder application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MAX_LEN 60

int ReadLine(char str[], int n);

int main(void){
    char *reminders[MAX_REMIND];
    char dayStr[3], msgStr[MAX_LEN + 1];
    int day, i, j, numRemind = 0;

    for(;;){
        if(numRemind == MAX_REMIND){
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if(day == 0){
            break;
        }
        sprintf(dayStr, "%2d", day);
        ReadLine(msgStr, MAX_LEN);

        for(i = 0; i < numRemind; i++){
            if(strcmp(dayStr, reminders[i]) < 0){
                break;
            }
        }

        for(j = numRemind; j > i; j--){
            reminders[j] = reminders[j-1];
        }
        
        reminders[i] = malloc(2 + strlen(msgStr) + 1);
        if(reminders[i] == NULL){
            printf("-- No space left --\n");
            break;
        }

        strcpy(reminders[i], dayStr);
        strcat(reminders[i], msgStr);

        numRemind++;
    }

    printf("\nDay Reminder\n");
    for(i = 0; i< numRemind; i++){
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

int ReadLine(char str[], int n){
    int ch, i = 0;

    while ((ch = getchar()) != '\n'){
        if (i < n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}