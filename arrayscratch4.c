#include <stdio.h>

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

//functions
void printArray(struct map hole[MAPSIZE][MAPSIZE]);
int sumTreasure(struct map hole[MAPSIZE][MAPSIZE]);
void printCrew(struct pirate member[NUMCREW]);

int setup(struct map hole[MAPSIZE][MAPSIZE], struct pirate member[NUMCREW]);
void dig(struct map * hole, struct pirate * member, int curpirate, int curX, int curY);

void evacuate(struct map hole[MAPSIZE][MAPSIZE], int *treasureSum);

int main() {
    int i, j, hour, treasureSum;
    char filename[20];

    struct pirate member[NUMCREW];
    struct map hole[MAPSIZE][MAPSIZE];

    // Set filename to NULL
    FILE * ifp = NULL;
    // Ask user for the file name
    while (ifp == NULL) {
        printf("What is the name of the file?\n");
        scanf("%s", &filename);
        ifp = fopen(filename, "r");
    }


    // Reads map array from file
    for(i = 0; i < MAPSIZE; i++) {
        for(j = 0; j < MAPSIZE; j++) {
            fscanf(ifp, "%d", &hole[i][j].sand);
            fscanf(ifp, "%d", &hole[i][j].treasure);
            treasureSum = treasureSum + hole[i][j].treasure;
        }
    }

    //reads crew info from file
    for(i = 0; i < 8; i++) {
        fscanf(ifp, "%d", &member[i].dig);
        fscanf(ifp, "%d", &member[i].carry);
    }


    //call to find total num of treasure
    //sumTreasure(hole, &treasureLeft, &flag);

    //printArray(hole);


    for(i = 0; i < HOURS; i++) {


        printf("\nYou have %d hours left to dig up the treasure.\n", HOURS-i);
        printCrew(member);
        //printf("i main: %d", i);    //test

        //setup(hole, member);
        if(setup(hole, member) == 1) {
            break;
            //printf("BREAK\n");
        }
        //printf("i main: %d", i);    //test


    }
    //turn setup into int, in main: if int == 1, break

    //run if need to evacuate
    evacuate(hole, &treasureSum);




    fclose(ifp);
    return 0;
}

void evacuate(struct map hole[MAPSIZE][MAPSIZE], int *treasureSum) {
    int i, j, treasureLeft;

    treasureLeft = 0;

    for(i = 0; i < MAPSIZE; i++) {
        for(j = 0; j < MAPSIZE; j++) {
            treasureLeft = treasureLeft + hole[i][j].treasure;
        }
    }

    if(treasureLeft > 0) {
        printf("\nYou are forced to evacuate the island. You have claimed %d pieces of the pirate's treasure!\n", *treasureSum - treasureLeft);
    }

}


//need to send curX, curY, curpirate to next function
int setup(struct map hole[MAPSIZE][MAPSIZE], struct pirate member[NUMCREW]) {
    int i, curpirate, curX, curY;


    for(i = 0; i < NUMCREW; i++) {
        curpirate = i;

        printf("\nWhere would you like to send crew member %d?\n", curpirate+1);
        printArray(hole);
        printf("\n");
        scanf("%d %d", &curX, &curY);
        //dig function: updates array based on pirate and user set hole
        //              also prints reactionary comments:  no sand left, etc.
        curX = curX - 1;
        curY = curY - 1;
        dig(&hole[curX][curY], &member[curpirate], curpirate, curX, curY);
        //printf("YOU ARE HERE 1\n");

        if(sumTreasure(hole) == 1) {
            //printf("THIS RAN\n"); TEST
            return 1;
        }
    }


}

void dig(struct map * hole, struct pirate * member, int curpirate, int curX, int curY) {
    //printf("YOU ARE HERE 2\n"); //TEST TEST
    int cur_dig_rate, cur_carry_rate, i, j;

    //if hole is already fully looted
    if(hole->treasure == 0) {
        printf("\nThis section has already been cleared.\n");
        //printf("SAND LEFT %d \n", hole->sand); //TEST TEST

    }

    //if hole isn't empty, enter loop
    else {
        cur_dig_rate = member->dig;
        //printf("DIG RATE: %d\n", cur_dig_rate); //TEST TEST
        cur_carry_rate = member->carry;

        //MAIN LOOP--------------------------------------
        //if sand left
        if(hole->sand > 0) {
            hole->sand = hole->sand - cur_dig_rate;

            //printf("SAND LEFT %d \n", hole->sand); //TEST TEST

            //if dig resulted in removing all sand
            if(hole->sand <= 0) {
                hole->sand = 0;
                printf("\nYou have removed all the sand from this section!\n");
                //printf("SAND LEFT %d \n", hole->sand); //TEST TEST

            }
            //if dig resulted in removing some sand
            else if(hole->sand > 0) {
                printf("\nYou have removed some of the sand from this section.\n");
                //printf("SAND LEFT %d \n", hole->sand); //TEST TEST
            }

        }

        //MAIN LOOP-------------------------------------
        //if no sand left
        //made this else if so only one or the other can run
        else if(hole->sand <= 0) {
            hole->treasure = hole->treasure - cur_carry_rate;

            //if statement: if carry resulted in removing all treasure
            if(hole->treasure <= 0) {
                hole->treasure = 0;
                printf("\nYou take all of the treasure back to the ship!\n");
            }

            //if statement: if carry resulted in removing some treasure
            else if(hole->treasure > 0) {
                printf("\nYou take some of the treasure back to ship.\n");
            }
        }

    }

}



void printArray(struct map hole[MAPSIZE][MAPSIZE]) {
    int i, j;
    for(i = 0; i < MAPSIZE; i++) {
        for(j = 0; j < MAPSIZE; j++) {
            if(hole[i][j].treasure == 0) {
                printf("-\t");
            }
            else if(hole[i][j].sand > 0) {
                printf("%ds\t", hole[i][j].sand);
            }
            else if(hole[i][j].sand == 0) {
                printf("%dT\t", hole[i][j].treasure);
            }

        }
        printf("\n");
    }
}


int sumTreasure(struct map hole[MAPSIZE][MAPSIZE]) {
    int j, k, treasureLeft = 0;
    //int one = 1;


    treasureLeft = 0;

    for(j = 0; j < MAPSIZE; j++) {
        for(k = 0; k < MAPSIZE; k++) {
            treasureLeft = treasureLeft + hole[j][k].treasure;
        }
    }

    if(treasureLeft == 0) {
        printf("\nAll of the pirate's treasure belongs to you now!\n");
        //return one;
        return 1;   //test
    }
    else {
        return 0;
    }

    //printf("TREASURE LEFT: %d", treasureLeft); //TEST
}

void printCrew(struct pirate member[NUMCREW]) {
    int i, j;

    printf("Crew\tDig\tCarry\n");
    for(i = 0; i < NUMCREW; i++) {
        printf("%d\t%d\t%d\n", i+1, member[i].dig, member[i].carry);
    }
}













