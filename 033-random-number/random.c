//Randomly generate a number from 1 - 100 and let the user guess

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int secretNumber;

void InitializeNumberGenerator(void);
int ChooseNewSecretNumber(void);
void ReadGuesses(int secretNumber);

int main(void){
    char command;
    int secretNumber;

    printf("Guess a number from 1 to %d\n", MAX_NUMBER);
    InitializeNumberGenerator();
    do {
        secretNumber = ChooseNewSecretNumber();
        printf("A new number has been chosen.\n");
        ReadGuesses(secretNumber);
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while(command == 'y' || command =='Y');

    return 0;
}

void InitializeNumberGenerator(void){
    srand((unsigned) time(NULL));
}

int ChooseNewSecretNumber(void){
    return rand() % MAX_NUMBER + 1;
}

void ReadGuesses(int secretNumber){
    int guess, numGuesses = 0;

    for(;;){
        numGuesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secretNumber){
            printf("You won in %d guesses!\n", numGuesses);
            return;
        }
        else if(guess < secretNumber){
            printf("Too low; try again\n");
        } else {
            printf("Too high; try again\n");
        }
    }
}