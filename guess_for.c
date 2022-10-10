//Joshua Taggart
//This program plays a simple guessing game
//A while loop is used to allow multiple guesses

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3

int main() {
    int num, guess, num_guess = 0, flag = 0;

    //seed the random number generator
    srand(time(0));

    //generate a random value between 1 and 10
    num = rand() % 10 + 1;

    //num_guess++ increments by 1
    for(num_guess = 0; num_guess < MAX; num_guess++) {
        printf("Guess #%d: Guess the secret number!\n", num_guess+1);
        scanf("%d", &guess);

        if(guess == num) {
            printf("You guessed the secret number!\n");
            flag = 1;
            break;
        }

    }

    if(!flag)
        printf("You ran out of guesses.\n");
        printf("Sorry, the secret number was %d.\n", num);

    return 0;
}
