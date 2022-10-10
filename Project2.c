/*Joshua Taggart
 * This program will determine if someone can join the ship
 * crew based on a series of questions.
 */

// pre-processor directives
#include <stdio.h>

// Defined required distance the user must be able to swim.
#define REQ_SWIM_DIST 100

//main function
int main() {
    // swim_dist is the variable that stores the distance the user can swim.
    int swim_dist;
    // These two variables store the yes or no variable for the user's ability
    // to dig and swim.
    char digging_like, swim_ability;

    printf("Do you like digging for treasure?\n");
    scanf(" %c", &digging_like);

    printf("Are you able to swim?\n");
    scanf(" %c", &swim_ability);

    // If the user cannot swim, the third prompt doesn't appear,
    // They cannot join the crew.
    if (swim_ability == 'N' || 'n')
        printf("You may not join the crew.\n");

    // If the user can swim, the code continues to ask the third prompt.
    else {
        printf("How many meters are you able to swim?\n");
        scanf("%d", &swim_dist);

        // If they don't like digging they cannot join the crew.
        if (digging_like == 'N')
            printf("You may not join the crew.\n");

        // If they cannot swim at least 100 meters they cannot join the crew.
        else if (swim_dist < REQ_SWIM_DIST)
            printf("You may not join the crew.\n");

        // This runs if the user chose yes to the first 2 prompts, and can swim
        // at least 100 meters.
        else
            printf("You may join the pirate crew! Arr!\n");
        }


    return 0;
}
