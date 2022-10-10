/* Joshua Taggart
   COP 3223
   11/14/20
   Assignment #7
 */

//Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constants for Arrays
#define STRLENGTH 30
#define NUMCREW 5
#define NUMSUPPLIES 4

//Constants for Distances (measured in miles)
#define CANARY 1261
#define GRENADA 3110
#define FINAL 500
#define DISTANCE 4871

//Function Signatures - do not change these
void setup(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int supplies[NUMSUPPLIES], int *captaintype, int *funds, int *distanceperday);
int countcrew(int crewstatus[NUMCREW]);
void printstatus(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW]);
void getsupplies(char supplytypes[NUMSUPPLIES][STRLENGTH], int supplies[NUMSUPPLIES], int *funds);
void dailyreport(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int supplies[NUMSUPPLIES], int funds, int traveled);
void rest(int supplies[NUMSUPPLIES], char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int *days);
int fish();
int max(int a, int b);
int min(int a, int b);
void event(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int *days, int supplies[NUMSUPPLIES]);

//Main function - This is the final version of main.  Any changes you make while
//creating the functions should be removed prior to submission.
int main(void) {
    //crewnames and supplytypes are arrays of strings to store the names of the crew members
    //and the types of supplies that can be purchased and taken on the voyage
    char crewnames[NUMCREW][STRLENGTH];
    char supplytypes[NUMSUPPLIES][STRLENGTH] = {"Food", "Clothes", "Ship Parts", "Shovels"};
    //stop indicates whether or not the user would like to stop at a port
    //crewstatus indicates the status of each crew member, corresponding to the order of names
    //supplies has a total for each type of supply, corresponding to the order of supplies
    char stop;
    int crewstatus[NUMCREW], supplies[NUMSUPPLIES];
    //the distanceperday and funds depends on the captaintype the user selects
    //day is the current day, traveled is the total miles traveled, i is a loop counter
    //and action stores the intended action of the user for the day
    int distanceperday, captaintype, funds, traveled=0, day=1;
    int i, action;

    //seed the pseudorandom number generator
    srand(time(0));

    //initialize each variable with information from the user
    setup(crewnames, crewstatus, supplies, &captaintype, &funds, &distanceperday);

    //begin the game by purchasing initial supplies
    printf("\nBefore leaving Port Marin, you should purchase some supplies.\n");
    getsupplies(supplytypes, supplies, &funds);

    //continue the voyage until the ship reaches the intended destination
    //if all crew members perish, the journey cannot continui
    while (traveled < DISTANCE && countcrew(crewstatus) > 0) {
        printf("\n\n--It is day #%d.--\n", day);

        //check to see if the ship has reached the next port
        if(traveled >= (GRENADA+CANARY) && traveled < (GRENADA + CANARY + distanceperday) ) {
            printf("You have arrived at Grenada, at the edge of the Carribbean Sea.\n");
            printf("Would you like to make port? (Y/N)\n");
            scanf(" %c", &stop);

            if (stop == 'Y' || stop == 'y')
                getsupplies(supplytypes, supplies, &funds);

            traveled = (GRENADA+CANARY) + distanceperday;
        }
        else if (traveled >= CANARY && traveled < (CANARY + distanceperday) ) {
            printf("You have arrived at the Canary Islands.\n");
            printf("Would you like to make port? (Y/N)\n");
            scanf(" %c", &stop);

            if (stop == 'Y' || stop == 'y')
                getsupplies(supplytypes, supplies, &funds);

            traveled = CANARY + distanceperday;
        }
        //if between destinations: print the daily report and process the user's action for the day
        else {
            dailyreport(crewnames, crewstatus, supplies, funds, traveled);

            printf("\nWhat would you like to do?\n");
            printf("1 - Fish\n");
            printf("2 - Rest\n");
            printf("3 - Continue\n");
            scanf("%d", &action);

            if(action == 1) {
                supplies[0] += fish();
            }
            else if(action == 2) {
                day--;
                rest(supplies, crewnames, crewstatus, &day);
            }
            else {
                traveled += distanceperday;
                supplies[0] = max(supplies[0] - countcrew(crewstatus) * 2, 0);      //make sure to avoid subtracting to negatives
                event(crewnames, crewstatus, &day, supplies);
            }
        }
        day++;
    }

    printf("\n\n");

    //The final printout changes based on which condition broke the while loop
    if (countcrew(crewstatus) == 0) {
        printf("Your crew has perished in the search for treasure. :(\n");

        printstatus(crewnames, crewstatus);
    }
    else {
        printf("Your crew has made it safely to the island.\n");

        printstatus(crewnames, crewstatus);

        if(supplies[3] >= countcrew(crewstatus))
            printf("You have enough shovels to dig up the treasure!\n");
        else
            printf("Unfortunately, you will not be able to dig up the treasure.\n");
    }

    return 0;
}

//Pre-conditions:  none
//Post-conditions: each input parameter should be assigned an initial value
void setup(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int supplies[NUMSUPPLIES], int *captaintype, int *funds, int *distanceperday) {
    int i;

    printf("You may now take your ship and crew from Port Marin, Spain to the hidden island in the Caribbean on the old pirate's map.\n");

    printf("\nHow will you travel?\n");
    printf("1. - As a merchant\n");
    printf("2. - As a privateer\n");
    printf("3. - As a pirate\n");
    scanf("%d", captaintype);

    // Merchant option
    // Sets funds and distance per day for merchant
    if (*captaintype == 1) {
        printf("As a merchant, you begin your trip with 1000 gold pieces.\n");
        printf("You will be sailing your Carrack, with an average speed of 80 miles per day.\n");
        *funds = 1000;
        *distanceperday = 80;
    }

    // Privateer option
    // Sets funds and distance per day for privateer
    if (*captaintype == 2) {
        printf("As a privateer, you begin your trip with 900 gold pieces.\n");
        printf("You will be sailing your Galleon, with an average speed of 90 miles per day.\n");
        *funds = 900;
        *distanceperday = 90;
    }

    // Pirate option
    // Sets funds and distance per day for pirate
    if (*captaintype == 3) {
        printf("As a pirate, you begin your trip with 800 gold pieces.\n");
        printf("You will be sailing your Clipper, with an average speed of 100 miles per day.\n");
        *funds = 800;
        *distanceperday = 100;
    }

    // Sets captain name in 0 spot of crewnames array
    printf("\nWhat is your name, Captain?\n");
    scanf("%s", crewnames[0]);

    // Sets 4 crewmates names in 1-4 spots of crewnames array
    printf("Who are the other members of your crew?\n");
    for (i = 1; i < NUMCREW; i++) {
        printf("%d: ", i);
        scanf("%s", crewnames[i]);
    }

    // Set crew status to 2, healthy
    for (i = 0; i < NUMCREW; i++) {
        crewstatus[i] = 2;
    }
    // Set amount of supplies to 0. array: food, clothes, ship parts, shovels
    for (i = 0; i < NUMSUPPLIES; i++) {
        supplies[i] = 0;
    }

}

//Pre-conditions:  crewstatus is an array of numerical indicators for the status of each crew member
//                 0 - deceased, 1 - ill, 2 - healthy
//Post-conditions: returns the number of crew members that are alive
int countcrew(int crewstatus[NUMCREW]) {
    int i, alive_crewmembers;

    alive_crewmembers = 0;
    // Goes through crewstatus, if status is > 0, they are alive
    // Adds +1 to alive_crewmembers for every alive crewmate
    for (i = 0; i < NUMCREW; i++) {
        if (crewstatus[i] > 0)
            alive_crewmembers++;
    }
    return alive_crewmembers;
}

//Pre-conditions:  crew names is an array of strings for the crew members
//                 crewstatus is an array of numerical indicators for the status of each crew member
//                 0 - deceased, 1 - ill, 2 - healthy
//Post-conditions: none
void printstatus(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW]) {
    int i;
    char status[3][STRLENGTH] = {"Deceased", "Ill", "Healthy"};

    for (i = 0; i < NUMCREW; i++) {
        // Set healthy status
        if (crewstatus[i] == 2){
            printf("%s: %s\n", crewnames[i], status[2]);
        }
        // Set ill status
        else if (crewstatus[i] == 1) {
            printf("%s: %s\n", crewnames[i], status[1]);
        }
        // Set deceased status
        else if (crewstatus[i] == 0) {
            printf("%s: %s\n", crewnames[i], status[0]);
        }
    }
}


//Pre-conditions:  supplytypes in an array of strings and gives the name of each supply type
//                 supplies is an array of integers representing how many of each type the crew has
//                 funds represents how many gold pieces the crew has to spend
//Post-conditions: the user may choose to buy supplies: incrementing values in supplies and
//                 decrementing funds
void getsupplies(char supplytypes[NUMSUPPLIES][STRLENGTH], int supplies[NUMSUPPLIES], int *funds) {
    int menu, num_items;

    printf("\nYou have %d gold pieces.\n", *funds);

    while (menu != 5) {
        // Prints menu
        printf("Available Supplies:\n");
        printf("1.  Food - 1 gold pieces\n");
        printf("2.  Clothes - 2 gold pieces\n");
        printf("3.  Ship Parts - 20 gold pieces\n");
        printf("4.  Shovels - 10 gold pieces\n");
        printf("5.  Leave Store\n");
        scanf("%d", &menu);

        // Buying food
        // Updates funds and supplies array
        if (menu == 1) {
            num_items = 0;
            printf("How many pounds of food do you want to buy?\n");
            scanf("%d", &num_items);

            // Won't purchase if funds aren't high enough
            if (num_items*1 > *funds)
                printf("Sorry, you cannot afford that much food.\n");
            else {
                *funds = *funds - (num_items*1);
                supplies[0] += num_items;
            }
            printf("\nYou have %d gold pieces.\n", *funds);
        }
        // Buying clothes
        // Updates funds and supplies array
        if (menu == 2) {
            num_items = 0;
            printf("How many sets of clothes do you want to buy?\n");
            scanf("%d", &num_items);

            // Won't purchase if funds aren't high enough
            if (num_items*2 > *funds)
                printf("Sorry, you cannot afford that many sets of clothes.\n");
            else {
                *funds = *funds - (num_items*2);
                supplies[1] += num_items;
            }
            printf("\nYou have %d gold pieces.\n", *funds);
        }
        // Buying ship parts
        // Updates funds and supplies array
        if (menu == 3) {
            num_items = 0;
            printf("How many extra ship parts do you want to buy?\n");
            scanf("%d", &num_items);

            // Won't purchase if funds aren't high enough
            if (num_items*20 > *funds)
                printf("Sorry, you cannot afford that many ship parts.\n");
            else {
                *funds = *funds - (num_items*20);
                supplies[2] += num_items;
            }
            printf("\nYou have %d gold pieces.\n", *funds);
        }
        // Buying shovels
        // Updates funds and supplies array
        if (menu == 4) {
            num_items = 0;
            printf("How many shovels do you want to buy?\n");
            scanf("%d", &num_items);

            // Won't purchase if funds aren't high enough
            if (num_items*10 > *funds)
                printf("Sorry, you cannot afford that many shovels.\n");
            else {
                *funds = *funds - (num_items*10);
                supplies[3] += num_items;
            }
            printf("\nYou have %d gold pieces.\n", *funds);

        }
    }
}

//Pre-conditions:  crew names is an array of strings for the crew members
//                 crewstatus is an array of numerical indicators for the status of each crew member
//                 0 - deceased, 1 - ill, 2 - healthy
//                 supplies is an array of integers representing how many of each type the crew has
//                 funds represents how many gold pieces the crew has to spend
//                 traveled represents the total number of miles the ship has traveled from the beginning
//Post-conditions: none
void dailyreport(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int supplies[NUMSUPPLIES], int funds, int traveled) {
    printf("You have traveled %d miles.\n", traveled);     //doesnt need *
    printstatus(crewnames, crewstatus);
    printf("\n");
    printf("You have %d gold pieces.\n", funds);           //doesnt need *
    printf("You have %d pounds of food.\n", supplies[0]);

    // Measures distance if between start and canary
    if (traveled < CANARY) {
        printf("You are %d miles from your next destination.\n\n", CANARY-traveled);
    }
    // Measures distance if between canary and grenada
    else if (traveled > CANARY && traveled < GRENADA+CANARY) {
        printf("You are %d miles from your next destination.\n\n", (GRENADA+CANARY)-traveled);
    }
    // Measures distance if between grenada and final
    else if (traveled > GRENADA+CANARY && traveled < DISTANCE) {
        printf("You are %d miles from your next destination.\n\n", DISTANCE-traveled);
    }

}

//Pre-conditions:  a and b are both integers
//Post-conditions: the larger value will be returned
int max(int a, int b) {
    int return_val;

    // If a is greater than b, return_val becomes a
    if (a > b)
        return_val = a;
    // If b is greater than a, return_val becomes b
    else
        return_val = b;

    return return_val;
}

//Pre-conditions:  a and b are both integers
//Post-conditions: the smaller value will be returned
int min(int a, int b) {
    int return_val;

    // If a is less than b, return_val becomes a
    if (a < b)
        return_val = a;
    // If b is less than a, return_val becomes b
    else
        return_val = b;

    return return_val;
}

//Pre-conditions:  supplies is an array of integers representing how many of each type the crew has
//                 crew names is an array of strings for the crew members
//                 crewstatus is an array of numerical indicators for the status of each crew member
//                 0 - deceased, 1 - ill, 2 - healthy
//                 days represents the current day
//Post-conditions: the user will select a number of days to rest for. update days to reflect this number
//                 there is a small chance an ill crew member will recover during rest days
void rest(int supplies[NUMSUPPLIES], char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int *days) {
    int rest_days, i, rand_value1, rand_value2;

    printf("How many days would you like to rest for?\n");
    scanf("%d", &rest_days);

    *days = *days + rest_days;

    // If crew member is still alive, lose 2 pounds of food per person
    for (i = 0; i < NUMCREW; i++) {
        if(crewstatus[i] > 0) {
            supplies[0] = supplies[0] - (rest_days*2);
        }
    }

    // Makes sure food doesn't go negative
    if (supplies[0] < 0) {
        supplies[0] = 0;
    }

    // Randomize 0 or 1
    rand_value1 = rand() % 2;
    // Randomly choose one crewmember
    rand_value2 = rand() % 6;

    // Randomly recover a crewmate if they are sick
    if (rand_value1 == 1) {
        if(crewstatus[rand_value2] == 1) {
            crewstatus[rand_value2] = 2;
            printf("%s has recovered.\n", crewnames[rand_value2]);
        }
    }
}

//Pre-conditions:  none
//Post-conditions: returns the number of pounds of fish gained by the ship
int fish() {
    int value, total_fish;

    //random value: 0, 1, 2, or 3
    value = rand() % 4;
    total_fish = value*50;

    printf("Your crew lowers the nets and pulls up %d pounds of fish.\n", total_fish);

    return total_fish;
}

//Pre-conditions:  crew names is an array of strings for the crew members
//                 crewstatus is an array of numerical indicators for the status of each crew member
//                 0 - deceased, 1 - ill, 2 - healthy
//                 days represents the current day
//                 supplies is an array of integers representing how many of each type the crew has
//Post-conditions: the status of a crew member or supplies may be affected by a random event,
//                 some events cause the ship to be delayed a certain number of days
void event(char crewnames[NUMCREW][STRLENGTH], int crewstatus[NUMCREW], int *days, int supplies[NUMSUPPLIES]) {
    int value, ship_parts, food_gained, food_lost, rand_crew, i;

    // Random value between 0 and 9
    // This picks one of the possible events
    value = rand() % 10;

    // Checks if crew is out of food
    // If crew is out of food, event number increases by 2
    if (supplies[0] == 0) {
        printf("You have no food.\n");
        value = value + 2;
        // Make sure the event number doesn't exceed 9 when 2 is added to it
        if (value > 9) {
            value = 9;
        }
    }

    if (value == 3) {
        // Randomize number between 1 and 4
        ship_parts = rand() % 4 + 1;
        *days = *days + 1;
        supplies[2] += ship_parts;

        // Reduce 2 food per alive person for 1 day
        for (i = 0; i < NUMCREW; i++) {
            if (crewstatus[i] == 1 || crewstatus[i] == 2)
                supplies[0] = supplies[0] - 2;
        }
        // Make sure food doesn't go negative
        if (supplies[0] < 0)
            supplies[0] = 0;

        printf("Another pirate ship pulls alongside and attacks!\n");
        printf("You fend them off and take %d extra ship parts.", ship_parts);
        printf("You take the day recovering.\n");
    }

    if (value == 4) {
        // Randomize number between 10 and 60 inclusive
        food_gained = rand() % 60 + 10;
        *days = *days + 1;
        supplies[0] += food_gained;

        // Reduce 2 food per alive person for 1 day
        for (i = 0; i < NUMCREW; i++) {
            if (crewstatus[i] == 1 || crewstatus[i] == 2)
                supplies[0] = supplies[0] - 2;
        }
        // Make sure food doesn't go negative
        if (supplies[0] < 0)
            supplies[0] = 0;

        printf("Another pirate ship pulls alongside and attacks!\n");
        printf("You fend them off and take %d pounds of their food.\n", food_gained);
        printf("You spend the day recovering.\n");
    }

    if (value == 5) {
        // Randomize number between 5 and 55
        food_lost = rand() % 55 + 5;
        *days = *days + 1;
        supplies[0] -= food_lost;

        // Reduce 2 food per alive person for 1 day
        for (i = 0; i < NUMCREW; i++) {
            if (crewstatus[i] == 1 || crewstatus[i] == 2)
                supplies[0] = supplies[0] - 2;
        }
        // Make sure food doesn't go negative
        if (supplies[0] < 0)
            supplies[0] = 0;

        printf("Another pirate ship pulls alongside and attacks!\n");
        printf("They took %d pounds of food and you spend the day recovering.\n", food_lost);
    }

    if (value == 6) {
        *days = *days + 1;

        // Reduce 2 food per alive person for 1 day
        for (i = 0; i < NUMCREW; i++) {
            if (crewstatus[i] == 1 || crewstatus[i] == 2)
                supplies[0] = supplies[0] - 2;
        }
        // Make sure food doesn't go negative
        if (supplies[0] < 0)
            supplies[0] = 0;

        printf("Fog surrounds your ship. Drop anchor for one day.\n");
    }

    if(value == 7) {
        *days = *days + 2;

        // Reduce 2 food per alive person for 2 days
        for (i = 0; i < NUMCREW; i++) {
            if (crewstatus[i] == 1 || crewstatus[i] == 2)
                supplies[0] = supplies[0] - 4;
        }
        // Make sure food doesn't go negative
        if (supplies[0] < 0)
            supplies[0] = 0;

        printf("An ocean storm batters your ship. Drop anchor for two days.\n");
    }

    if (value == 8) {
        printf("A part of your ship has broken!\n");

        // This runs if the crew has enough supplies to repair
        if (supplies[2] >= 1) {
            supplies[2] = supplies[2] - 1;
            *days = *days + 1;

            // Reduce 2 food per alive person for 1 day
            for (i = 0; i < NUMCREW; i++) {
                if (crewstatus[i] == 1 || crewstatus[i] == 2)
                    supplies[0] = supplies[0] - 2;
            }
            // Make sure food doesn't go negative
            if (supplies[0] < 0)
                supplies[0] = 0;
            // Make sure ship parts doesn't go negative
            if (supplies[2] < 0)
                supplies[2] = 0;

            printf("You replace the broken part. It takes one day.\n");
        }

        else {
            *days = *days + 3;
            // Reduce 2 food per alive person for 3 days
            for (i = 0; i < NUMCREW; i++) {
                if (crewstatus[i] == 1 || crewstatus[i] == 2)
                    supplies[0] = supplies[0] - 6;
            }
            // Make sure food doesn't go negative
            if (supplies[0] < 0)
                supplies[0] = 0;

            printf("You have no replacement parts. It takes three days to repair.\n");
        }
    }

    if (value == 9) {
        // Randomize number between 0 and 5
        // This indicates choosing a random crew member
        rand_crew = rand() % 5;

        // If the crewmate is healthy, they are now sick
        if (crewstatus[rand_crew] == 2) {
            crewstatus[rand_crew] = 1;
            printf("%s has fallen ill.\n", crewnames[rand_crew]);
        }

        // If they are sick, they are now dead
        else if (crewstatus[rand_crew] == 1) {
            crewstatus[rand_crew] = 0;
            printf("%s has died.\n", crewnames[rand_crew]);
        }
    }

}



