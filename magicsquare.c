//Sarah Angell
//Magic Square: this program uses a 2 dimensional array
//to determine if a square of numbers is a magic square

#include <stdio.h>

#define SIZE 3

int main() {
    int square[SIZE][SIZE];
    int freq[SIZE*SIZE+1];
    int i, j, sum, checksquare = 1;
    FILE * ifp = fopen("square.txt", "r");
    /*
    //ask the user for the square
    printf("Enter the values for the magic square:\n");
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            scanf("%d", &square[i][j]);
    */

    //get information from a file
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            fscanf(ifp, "%d", &square[i][j]);


    //print out the square
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            printf("%d\t", square[i][j]);
        printf("\n");
    }

    //check for frequency
    for(i = 0; i < SIZE*SIZE+1; i++)
        freq[i] = 0;

    //traverse the square, adding values to the freq
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++) {
            if (square[i][j] < 1 || square[i][j] > SIZE*SIZE)
                checksquare = 0;
            freq[square[i][j]]++;
        }

    //check that all frequencies are 1
    for(i = 1; i < SIZE*SIZE+1; i++)
        if(freq[i] != 1)
            checksquare = 0;

    //check the sum of the rows
    for(i = 0; i < SIZE; i++) {
        sum = 0;

        for(j = 0; j < SIZE; j++)
            sum += square[i][j];

        if(sum != (SIZE * (SIZE * SIZE +1))/2)
            checksquare = 0;
    }

    //check the sums of the columns
    for(j = 0; j < SIZE; j++) {
        sum = 0;

        for(i = 0; i < SIZE; i++)
            sum += square[i][j];

        if(sum != (SIZE * (SIZE * SIZE + 1))/2)
            checksquare = 0;
    }

    //check diagonals
    sum = 0;
    for(i = 0; i < SIZE; i++)
        sum += square[i][i];
    if(sum != (SIZE * (SIZE*SIZE+1))/2)
        checksquare = 0;

    sum = 0;
    for(i = 0; i < SIZE; i++)
        sum += square[i][SIZE-i-1];
    if(sum != (SIZE *(SIZE*SIZE+1))/2)
        checksquare = 0;



    if (checksquare)
        printf("This is a magic square!\n");
    else
        printf("This is not a magic square.\n");

    return 0;
}
