//Analyze a given poker hand

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define NUM_SYMBOLS 2

bool royalFlush, straight, flush, four, three;
int pairs;

void ReadCards(int cards[NUM_CARDS][NUM_SYMBOLS]);
void AnalyzeHand(int cards[NUM_CARDS][NUM_SYMBOLS]);
void PrintResult(void);

int main(void){
    int cards[NUM_CARDS][NUM_SYMBOLS];
    for(;;){
        ReadCards(cards);
        AnalyzeHand(cards);
        PrintResult();
    }
}

void ReadCards(int cards[NUM_CARDS][NUM_SYMBOLS]){
    char ch, rankCh, suitCh;
    int rank, suit;
    bool badCard, duplicateCard;
    int cardsRead = 0;

    for(int i = 0; i < NUM_CARDS; i++){
        for(int j = 0; j < NUM_SYMBOLS; j++){
            cards[i][j] = 0;
        }
    }

    while(cardsRead < NUM_CARDS){
        badCard = false;

        printf("Enter a card: ");
        rankCh = getchar();
        switch(rankCh){
                case '0': exit(EXIT_SUCCESS);
                case '2': rank = 0; break;
                case '3': rank = 1; break;
                case '4': rank = 2; break;
                case '5': rank = 3; break;
                case '6': rank = 4; break;
                case '7': rank = 5; break;
                case '8': rank = 6; break;
                case '9': rank = 7; break;
                case 't': case 'T': rank = 8; break;
                case 'j': case 'J': rank = 9; break;
                case 'q': case 'Q': rank = 10; break;
                case 'k': case 'K': rank = 11; break;
                case 'a': case 'A': rank = 12; break;
                default: badCard = true;       
        }

        suitCh = getchar();
        switch(suitCh){
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: badCard = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') badCard = true;
        
        if(badCard){
            printf("Bad card; ignored\n");
            continue;
        } 

        duplicateCard = false;
        for(int i = 0; i < cardsRead; i++){
            if(rank == cards[i][0] && suit == cards[i][1]){
                printf("Duplicate card; ignored\n");
                duplicateCard = true;
            }
        }

        if(!duplicateCard){
            cards[cardsRead][0] = rank;
            cards[cardsRead][1] = suit;
            cardsRead++;
        }   
    }
}

void AnalyzeHand(int cards[NUM_CARDS][NUM_SYMBOLS]){
    int cardsCounted;
    int numConsec = 0;
    int rank, suit, rankCount;
    royalFlush = false;
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = false;

    // sort cards by rank
    for(int i = 0; i < NUM_CARDS; i++){
        // find the lowest rank first, switch it with the first card, then find the second lowest etc.
        int lowestRank = 13, lowestPos;
        int placeHolderRank, placeHolderSuit;
        for(int j = i; j < NUM_CARDS; j++){
            if(cards[j][0] < lowestRank){
                lowestRank = cards[j][0];
                lowestPos = j;
            }
        }
        placeHolderRank = cards[i][0];
        placeHolderSuit = cards[i][1];
        cards[i][0] = cards[lowestPos][0];
        cards[i][1] = cards[lowestPos][1];
        cards[lowestPos][0] = placeHolderRank;
        cards[lowestPos][1] = placeHolderSuit;
    }

    //check for flush
    suit = cards[0][1];
    for (int i = 1; i < NUM_CARDS; i++){
        if(suit != cards[i][1]){
            flush = false;
        }
    }

    //check for straight
    for(int i = 0; i < NUM_CARDS -1; i++){
        if(cards[i][0] + 1 != cards[i + 1][0]){
            straight = false;
        }
    }
    
    //check for ace-low straight
    if(cards[0][0] == 0 && cards[NUM_CARDS -1][0] == 12){
        straight = true;
        for(int i = 0; i < NUM_CARDS - 2; i++){
            if(cards[i][0] + 1 != cards[i + 1][0]){
                straight = false;
            }
        }
    }

    //check for royal flush
    if(flush && straight && cards[0][0] == 8){
        royalFlush = true;
    }

    // check for multiples of a kind
    for(int i = 0; i < NUM_CARDS; i++){
        rankCount = 0;
        for(int j = i; j < NUM_CARDS; j++){
            if(cards[i][0] == cards[j][0]){
                rankCount++;
            }
        }
        if(rankCount == 4) four = true;
        if(rankCount == 3) three = true;
        if(rankCount == 2) pairs++;
    }
}

void PrintResult(void){
    if(royalFlush)               printf("Royal Flush");
    else if (straight && flush)  printf("Straight Flush");
    else if(four)                printf("Four of a kind");
    else if(three && pairs == 1) printf("Full house");
    else if(flush)               printf("Flush");
    else if(straight)            printf("Straight");
    else if(three)               printf("Three of a kind");
    else if(pairs == 2)          printf("2 Pairs");
    else if(pairs == 1)          printf("Pair");
    else                         printf("High Card");

    printf("\n\n");
}