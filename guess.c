//Joshua Taggart
//This program plays a simple guessing game

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

    if (guess == num)
        printf("You guessed the number correctly!\n");
    else {
        printf("Sorry, you did not guess the right number.");
        printf("The secret number was %d.\n", num);
    }


    return 0;
}
