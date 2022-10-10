//Sarah Angell
//This program implements a 2D array
//for a multiplication table

#include <stdio.h>

#define ROWS 5
#define COLS 12

int main() {
    int multtable[ROWS][COLS];
    int i, j;

    //create the multiplication table
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            multtable[i][j] = (i + 1) * (j + 1);

    //print out the table
    /*
    for (i = 1; i <= COLS; i++)
        printf("    %2d", i);

    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d    %d", i+1, multtable[i][0]);

        for(j = 1; j < COLS; j++)
            printf("    %2d", multtable[i][j]);

        printf("\n");
    }*/

    printf("  ");
    for(i=1; i<=ROWS; i++)
        printf("    %2d", i);

    printf("\n");

    for (i = 0; i < COLS; i++) {
        printf("%2d    %2d", i+1, multtable[0][i]);

        for (j = 1; j < ROWS; j++)
            printf("    %2d", multtable[j][i]);

        printf("\n");
    }

    return 0;
}
