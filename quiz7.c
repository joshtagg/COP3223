//Joshua Taggart
//finds the best sum out of all the rows and all the columns

#include <stdio.h>

#define ROWS 20
#define COLS 5

int main() {
    FILE * ifp = fopen("marketing.txt", "r");
    int loop, numCases, best, sum;
    int grid[ROWS][COLS], i, j;

    fscanf(ifp, "%d", &numCases);

    for(loop = 0; loop < numCases; loop++) {
        for(i = 0; i < ROWS; i++)
            for(j = 0; j < COLS; j++)
                fscanf(ifp, "%d", &grid[i][j]);

        best = 0;

        for(i = 0; i < ROWS; i++) {
            sum = 0;
            for(j = 0; j < COLS; j++)
                sum += grid[i][j];

            if(sum > best)
                best = sum;
        }

        for(i = 0; i < COLS; i++) {
            sum = 0;
            for(j = 0; j < ROWS; j++)
                sum = sum + grid[j][i];

            if(sum > best)
                best = sum;
        }

        printf("%d\n", best);
    }



    fclose(ifp);
    return 0;
}
