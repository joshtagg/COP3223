/* Joshua Taggart, COP 3223C-0V07, Assignment #1, 9/6/2020
This program solves the pirate time problem
*/

// Pre-processor Directives
#include <stdio.h>
#include <math.h>

// Constants
// This constant is for defining the distance from Spain to the Caribbean
#define SPAIN_CAR_DIST 7228

// Main Function
int main() {
    // Variables
    int km_day = 0, num_members = 0;
    float trip_length_days = 0, oranges_needed = 0;

    /* This print statement asks the user how far they travel per day and
    records it in the km_day variable */
    printf("How many kilometers can your ship travel in one day?\n");
    scanf("%d", &km_day);

    /* This print statement asks the user how big the crew will be and records
    the number in the num_members variable */
    printf("How many crew members can your ship hold?\n");
    scanf("%d", &num_members);

    // This formula calculates the trip length in days
    trip_length_days = (float) SPAIN_CAR_DIST / km_day;

    // This is the formula that calculates the oranges needed for the full trip
    oranges_needed = (trip_length_days * num_members) * 0.5;

    // This print statement prints out the final answer to the problem
    printf("You will need %.2f oranges to make the trip!\n", oranges_needed);

    return 0;
}
