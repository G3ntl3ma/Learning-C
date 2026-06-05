//Evaluate a given expression from left to right

#include <stdio.h>

int main(void){
    float firstNum, secondNum;
    char ch;

    printf("Enter the expression: ");
    scanf("%f", &firstNum);

    while((ch = getchar()) != '\n'){

        scanf("%f", &secondNum);

        switch (ch){
            case '+': firstNum += secondNum; break;
            case '-': firstNum -= secondNum; break;
            case '*': firstNum *= secondNum; break;
            case '/': firstNum /= secondNum; break;
        }
    }
    
    printf("Value of the expression: %f\n", firstNum);
}