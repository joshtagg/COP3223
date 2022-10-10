//Joshua Taggart
//This program plays a simple guessing game
//A while loop is used to allow multiple guesses

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess;

    //seed the random number generator
    srand(time(0));

    //generate a random value between 1 and 10
    num = rand() % 10 + 1;

    printf("Guess a value between 1 and 10!\n");
    scanf("%d", &guess);

    while (guess != num) {
        printf("Sorry that is incorrect.\n");
        printf("Please guess again.\n");
        scanf("%d", &guess);

    }
    printf("Yay! You guessed the secret number!\n");

    return 0;
}
