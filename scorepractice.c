//Joshua Taggart
//This program predefines a score and then prints a response message based on the score
//Demonstrates the use  of implicitly nested if statements

#include <stdio.h>

int main() {
    int score;

    printf("What was your score?\n");
    scanf("%d", &score);

    if (score < 200)
        printf("Practice makes Perfect!\n");
    else if (score < 250)
        printf("You did well!\n");
    else if (score < 300)
        printf("You did great!\n");
    else
        printf("You did excellent!\n");

    return 0;
}
