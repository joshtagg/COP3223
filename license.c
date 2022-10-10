//Joshua Taggart
//This program determines if the user can apply for their driver's license

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 16
#define PRACTICE 50

int main() {
    int age, hours;
    char ans;

    printf("Enter your age here: ");
    scanf("%d", &age);

    printf("How many hours of driving practice have you completed?\n");
    scanf("%d", &hours);

    printf("Have you held a license in a different state? (Y/N)\n");
    scanf(" %c", &ans);

    //if everything in parenthesis is true OR answered y, then continue
    if ((age >= LIMIT && hours >= PRACTICE) || ans == 'Y')
        printf("You are old enough to apply for a driver's license!\n");
    else {
        printf("Sorry, you cannot apply for your license.\n");

        //missing age
        if (age < LIMIT)
            printf("Sorry, you must wait %d more years.\n", LIMIT - age);

        //missing hours
        if (hours < PRACTICE)
            printf("You need %d more hours of practice.\n", PRACTICE - hours);
    }

    return 0;
}
