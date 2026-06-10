//randomly draw a number of cards

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITES 4
#define NUM_RANKS 13

int main(void){
    bool inHand [NUM_SUITES][NUM_RANKS] = {false};
    int numCards, rank, suit;
    const char rankCode[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
    const char suitCode[] = {'c', 'd', 'h', 's'};

    srand((unsigned) time(NULL));

    printf("Enter amount of cards: ");
    scanf("%d", &numCards);

    printf("Your Cards:");
    while(numCards > 0){
        suit = rand() % NUM_SUITES;
        rank = rand() % NUM_RANKS;
        if (!inHand[suit][rank]){
            inHand[suit][rank] = true;
            numCards--;
            printf(" %c%c", rankCode[rank], suitCode[suit]);
        }
    }
    printf("\n");
    printf("random Number: %d\n", rand());
    return 0;
}