#include <stdio.h>

// Constants
#define NUMCREW 4
#define MAPSIZE 3
#define HOURS 8

struct map {
    int sand;
    int treasure;
};

struct pirate {
    int dig;
    int carry;
};

// Function Signatures
void printArray(struct map hole[MAPSIZE][MAPSIZE]);
int sumTreasure(struct map hole[MAPSIZE][MAPSIZE]);
void printCrew(struct pirate member[NUMCREW]);
int setup(struct map hole[MAPSIZE][MAPSIZE], struct pirate member[NUMCREW]);
void dig(struct map * hole, struct pirate * member, int curpirate, int curX, int curY);
void evacuate(struct map hole[MAPSIZE][MAPSIZE], int *treasureSum);

// Main loop
int main(void) {
    int i, j, treasureSum;
    char filename[20];

    // Set the pirate struct as a 1D array
    struct pirate member[NUMCREW];
    // Set the map struct as a 2D array
    // Set as a 2D array because it represents the map
    struct map hole[MAPSIZE][MAPSIZE];

    // Set filename to NULL
    FILE * ifp = NULL;
    // Ask user for the file name
    while (ifp == NULL) {
        printf("What is the name of the file?\n");
        scanf("%s", &filename);
        ifp = fopen(filename, "r");
    }

    // Reads map array from file, sets to map struct
    for (i = 0; i < MAPSIZE; i++) {
        for (j = 0; j < MAPSIZE; j++) {
            fscanf(ifp, "%d", &hole[i][j].sand);
            fscanf(ifp, "%d", &hole[i][j].treasure);
            // This finds the total sum of the initial amount of treasure.
            treasureSum = treasureSum + hole[i][j].treasure;
        }
    }

    // Reads crew info from file, sets to pirate struct
    for (i = 0; i < 8; i++) {
        fscanf(ifp, "%d", &member[i].dig);
        fscanf(ifp, "%d", &member[i].carry);
    }

    // This loop runs for each of the 8 hours
    for (i = 0; i < HOURS; i++) {
        printf("\nYou have %d hours left to dig up the treasure.\n", HOURS-i);
        printCrew(member);

        // If setup returns 1, that means sumTreasure returned 1
        // If sumTreasure returned 1, that means the user found all the treasure.
        // Since the user found all the treasure, the 8 hour loop should break.
        if (setup(hole, member) == 1) {
            break;
        }
    }

    // This runs after the 8 hour loop is finished
    evacuate(hole, &treasureSum);

    // Closes file
    fclose(ifp);
    return 0;
}

// This runs and determines if the users have found all of the treasure or not
// by the time the 8 hours has run.
// Pre-conditions: hole is an array
//                 treasureSum is an integer storing the total initial amount of treasure
// Post-conditions: returns a prints statement if the user did not find all of the treasure
void evacuate(struct map hole[MAPSIZE][MAPSIZE], int *treasureSum) {
    int i, j, treasureLeft;

    // This variable tracks the amount of treasure left.
    treasureLeft = 0;

    // This counts up the total amount of treasure left.
    for (i = 0; i < MAPSIZE; i++) {
        for (j = 0; j < MAPSIZE; j++) {
            treasureLeft = treasureLeft + hole[i][j].treasure;
        }
    }

    // If the user did not find all of the treasure it prints that they have to evacuate.
    if (treasureLeft > 0) {
        printf("\nYou are forced to evacuate the island. You have claimed %d pieces of the pirate's treasure!\n", *treasureSum - treasureLeft);
    }

}

// This is the main function that prompts the user
// This function also calls the dig, sumTreasure, and printArray function
// Pre-conditions: hole and member are arrays
// Post-conditions: asks the user for coordinates to send the current crew member
//                  returns 1 if all of the treasure has been found
int setup(struct map hole[MAPSIZE][MAPSIZE], struct pirate member[NUMCREW]) {
    int i, curpirate, curX, curY;

    for (i = 0; i < NUMCREW; i++) {
        curpirate = i;

        printf("\nWhere would you like to send crew member %d?\n", curpirate+1);
        // This will print the map
        printArray(hole);
        printf("\n");
        //curX and curY will hold the user inputed coordinate
        scanf("%d %d", &curX, &curY);
        curX = curX - 1;
        curY = curY - 1;
        // This calls the dig function which updates the user selected hole based on
        // the current pirate in use.
        dig(&hole[curX][curY], &member[curpirate], curpirate, curX, curY);

        // The loop breaks and returns 1 if all of the treasure has been found
        if (sumTreasure(hole) == 1) {
            return 1;
        }
    }
}

// This function updates the map when a crew member digs or takes treasure
// Pre-conditions: hole and member are arrays
//                 curpirate, curX, and curY are all integers
//                 the user has inputed a map coordinate under the integers curX and curY
// Post-conditions: Returns a print statement based on what the current crew member did
//                  (dig sand, remove treasure, did nothing)
void dig(struct map * hole, struct pirate * member, int curpirate, int curX, int curY) {
    int cur_dig_rate, cur_carry_rate, i, j;

    // If the user selected hole is already fully looted, this runs
    if (hole->treasure == 0) {
        printf("\nThis section has already been cleared.\n");
    }

    // If the user selected hole isn't empty, enter the loop
    else {
        // This sets the dig rate based on the current crew member.
        cur_dig_rate = member->dig;
        // This sets the treasure carry rate based on the current crew member.
        cur_carry_rate = member->carry;


        // If there is sand in the hole
        if (hole->sand > 0) {
            // Removes sand based on crew dig rate
            hole->sand = hole->sand - cur_dig_rate;

            // If the dig resulted in removing all sand
            if (hole->sand <= 0) {
                // This makes sure the sand doesn't display a negative number
                hole->sand = 0;
                printf("\nYou have removed all the sand from this section!\n");
            }

            // If the dig resulted in removing some sand
            else if (hole->sand > 0) {
                printf("\nYou have removed some of the sand from this section.\n");
                //printf("SAND LEFT %d \n", hole->sand); //TEST TEST
            }
        }

        // If the user selected hole has no sand left
        else if (hole->sand <= 0) {
            // Removes treasure based on crew treasure carry rate
            hole->treasure = hole->treasure - cur_carry_rate;

            // If all the treasure has been picked up
            if (hole->treasure <= 0) {
                // This makes sure the treasure doesn't display a negative number
                hole->treasure = 0;
                printf("\nYou take all of the treasure back to the ship!\n");
            }

            // If only some of the treasure has been picked up
            else if (hole->treasure > 0) {
                printf("\nYou take some of the treasure back to ship.\n");
            }
        }
    }
}

// This function prints out the map when it is updated
// Pre-conditions: hole is an array with the amount of sand and treasure in each hole
// Post-conditions: prints out the map array
void printArray(struct map hole[MAPSIZE][MAPSIZE]) {
    int i, j;
    for (i = 0; i < MAPSIZE; i++) {
        for (j = 0; j < MAPSIZE; j++) {
            // If there is no treasure or sand left, print a dash
            if (hole[i][j].treasure == 0) {
                printf("-\t");
            }
            // If there is sand left
            // Print the amount of sand followed by the letter "s"
            else if (hole[i][j].sand > 0) {
                printf("%ds\t", hole[i][j].sand);
            }
            // If there is no sand but treasure left
            // Print the amount of treasure followed by the letter "T"
            else if (hole[i][j].sand == 0) {
                printf("%dT\t", hole[i][j].treasure);
            }
        }
        printf("\n");
    }
}

// This function adds up the total amount of treasure
// If determines if the pirates have picked up all of the treasure or not
// Pre-conditions: hole is an array with the amount of sand and treasure in each hole
// Post-conditions: returns 1 if there is no treasure left
//                  returns 0 if treasure is still left
int sumTreasure(struct map hole[MAPSIZE][MAPSIZE]) {
    int j, k, treasureLeft = 0;

    // This stores the amount of treasure remaining
    treasureLeft = 0;

    // This loops through the map function and counts up the amount of treasure left
    for (j = 0; j < MAPSIZE; j++) {
        for (k = 0; k < MAPSIZE; k++) {
            treasureLeft = treasureLeft + hole[j][k].treasure;
        }
    }

    // If there is no more treasure remaining
    if (treasureLeft == 0) {
        printf("\nAll of the pirate's treasure belongs to you now!\n");
        // This return will end the dig function because there would
        // be no more treasure to dig up
        return 1;
    }
    // If there is still treasure remaining
    else {
        return 0;
    }
}

// This runs each time the hour changes, this prints the crew information
// Pre-conditions: member is an array with the information about each individual crew member
// Post-conditions: none
void printCrew(struct pirate member[NUMCREW]) {
    int i, j;

    printf("Crew\tDig\tCarry\n");

    // This loops through the crew struct and prints each member's stats
    for (i = 0; i < NUMCREW; i++) {
        printf("%d\t%d\t%d\n", i+1, member[i].dig, member[i].carry);
    }
}






