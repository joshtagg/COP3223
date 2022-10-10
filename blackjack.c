//Sarah Angell
//This program simulates a round of Blackjack
//it demonstrates pass-by-value and
//pass-by-reference functions

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int getCard();
//cant edit value of score1 and score2 within printWinner, same goes for getNextTurn
void printWinner(int score1, int score2);
int getNextTurn(int player, int score);
//modifies pScore at the memory level
void doTurn(int * pScore);

//main function
int main() {
    int curcard, score1=0, score2=0, done1=0, done2=0;
    srand(time(0));

    score1 = getCard() + getCard();
    score2 = getCard() + getCard();

    while (!done1 || !done2) {

        //if player 1 is still drawing cards:
        if(!done1 && getNextTurn(1, score1))
            doTurn(&score1);
        else
            done1 = 1;

        if (score1 > 21)
            done1 = 1;

        //if player 2 is still drawing cards:
        if(!done2 && getNextTurn(2, score2))
            doTurn(&score2);
        else
            done2 = 1;

        if(score2 > 21)
            done2 = 1;
    }

    printWinner(score1, score2);

    return 0;
}

//pre-condition: none, assumes the random number generator is already seeded
//post-condition: return the value of a card
int getCard() {
    //generate a random number that represents a card
    //A = 1, J = 11, Q = 12, K = 13
    int card = rand() % 13 + 1;

    if (card > 10)
        card = 10;

    return card;
}

//pre-conditions: score1 is the score for player 1, score2 is the score for player 2
//post-conditions: prints the winner based on their scores
void printWinner(int score1, int score2) {
    //player 1 wins if their score is higher than player 2
    //and player 1 hasn't busted
    if (score1 > score2 && score1 <= 21)
        printf("Player 1 wins!\n");
    else if (score2 > score1 && score2 <= 21)
        printf("Player 2 wins!\n");
    else if (score1 == score2 && score1 <= 21)
        printf("Both players tied!\n");
    else if (score1 > 21 && score2 <= 21)
        printf("Player 2 wins because Player 1 busted!\n");
    else if (score2 > 21 && score1 <=21)
        printf("Player 1 wins because Player 2 busted!\n");
    else
        printf("Both players busted! No one wins!\n");

    return;
}

//pre-conditions: player is the player number, score is their current score
//post-conditions: ask the user if they want another card, return their response
int getNextTurn(int player, int score) {
    int ans = -1;

    printf("Player %d, your current score is %d.\n", player, score);
    printf("Do you want another card? (Yes = 1, No = 0)\n");
    scanf("%d", &ans);

    while (ans < 0 || ans > 1) {
        printf("Sorry, that is invalid.\n");
        printf("Do you want another card? (Yes = 1, No = 0)\n");
        scanf("%d", &ans);
    }
    return ans;
}

//pre-conditions: pScore is a pointer to the user's score
//post-conditions: get a new card, add it to the players score and return
void doTurn(int * pScore) {
    int curcard = getCard();

    printf("Your new card value is %d.\n", curcard);
    *pScore += curcard;

    printf("Your current score is %d.\n", *pScore);

    return;
}




















