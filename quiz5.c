//Joshua Taggart
//This program will print your roommates pattern to the file called output.txt

#include <stdio.h>

int main() {
    int rows, stars, i, j;
    FILE * ofp = fopen("output.txt", "w");

    printf("How many rows for your star design?\n");
    scanf("%d", &rows);

    printf("How many stars on the first row?\n");
    scanf("%d", &stars);

    for (i = 0; i < rows; i++) {
        if(i % 2 == 0) {
            for(j = 0; j < stars; j++)
                fprintf(ofp, "* ");
        }
        else {
            for (j = 0; j < stars - 1; j++)
                fprintf(ofp, " *");
        }

        fprintf(ofp, "\n");

    }

    fclose(ofp);

    return 0;
}
