/* Joshua Taggart
 * This program will train the speed of the landing crew by
   averaging their timing of trips.
 */

#include <stdio.h>

int main() {
    int i, j, num_days = 0, num_trips = 0;
    // avg stores the average times based on the num of trips taken
    float avg = 0, time = 0;

    // Asks for num of days for the for loop
    printf("How many days will you observe the landing crew?\n");
    scanf("%d", &num_days);

    // This loop runs for the number of days. Asks for num of trips per day
    for (i = 0; i < num_days; i++) {
        printf("\nHow many trips were completed in day #%d?\n", i + 1);
        scanf("%d", &num_trips);

        // This loop runs for the num of trips and asks how long each trip was
        for (j = 0; j < num_trips; j++) {
            printf("How long was trip #%d\n", j + 1);
            scanf("%f", &time);
            // Formula calculates average time for num of trips
            avg = avg + (time / num_trips);
        } // End of second for-loop

        // Prints average time for each day
        printf("\nDay #%d: The average time was %.3f\n", i + 1, avg);
        // Resets average value for next day
        avg = 0;

    } // End of first for-loop

    return 0;
} // End of main
