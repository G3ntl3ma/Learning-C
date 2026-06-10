//simulate the game of craps

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int RollDice(void);
bool PlayGame(void);

int main(void){
    int wins = 0, losses = 0;
    bool lastGame;
    char con, ch;
    srand(time(NULL));

    do {
    lastGame = PlayGame();
    lastGame ? wins++ : losses++;
    printf("Play again? ");
    con = tolower(getchar());
    while ((ch = getchar()) != '\n' && con != EOF)
        ;
    } while(con == 'y');

    printf("Wins: %d Losses: %d\n", wins, losses);

    return 0;
}

int RollDice(void){
    int firstRoll, secondRoll, num;
    firstRoll = (rand() % 6) + 1;
    secondRoll = (rand() % 6) + 1;
    num = firstRoll + secondRoll;
    printf("You rolled: %d\n", num);
    return num;
}

bool PlayGame(void){
    int firstRoll, nextRoll;

    firstRoll = RollDice();
    if(firstRoll == 7 || firstRoll == 11){
        printf("You win!\n");
        return 1;
    } else if(firstRoll == 2 || firstRoll == 3 || firstRoll == 12){
        printf("You lose!\n");
        return 0;
    }
    printf("Your point is %d\n", firstRoll);

    for(;;){
        nextRoll = RollDice();
        if(nextRoll == 7){
            printf("You lose!\n");
            return 0;
        } else if(nextRoll == firstRoll){
            printf("You win!\n");
            return 1;
        }
    }
}