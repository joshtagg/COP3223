/* Joshua Taggart
This program solves the pirate time problem
*/

//pre-processor directives
#include <stdio.h>
#include <math.h>
//constants
#define SPAIN_CAR_DIST 7228
//#define ORANGE_MEMBER 0.5

//main function
int main() {
    //variables
    int km_day = 0, num_members = 0;
    float trip_length_days = 0, oranges_needed = 0;

    //comment
    printf("How many kilometers can your ship travel in one day?\n");
    scanf("%d", &km_day);

    printf("How many crew members can your ship hold?\n");
    scanf("%d", &num_members);

    trip_length_days = (float) SPAIN_CAR_DIST / km_day;

    oranges_needed = (trip_length_days * num_members) * 0.5;

    printf("You will need %.2f oranges to make the trip!\n", oranges_needed);

    return 0;
}
