//Sarah Angell
//This program demonstrates two
//one dimensional arrays working together
//Both arrays are the same size
//An integer array is sorted smallest to largest number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define SIZE 20

int main()  {
    int unsorted[SIZE], sorted[SIZE];
    int i, j, min, indexmin;

    srand(time(0));

    for (i = 0; i < SIZE; i++) {
        unsorted[i] = rand() % 50 + 1; //1-50
    }
    printf("Unsorted:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d\n", unsorted[i]);
    }

    for (i = 0; i < SIZE; i++) {
        min = unsorted[0]; //set min to first value of array
        indexmin = 0;

        for (j = 0; j < SIZE; j++)
            if (unsorted[j] < min) {
                min = unsorted[j];
                indexmin = j;
            }

        sorted[i] = min;
        unsorted[indexmin] = MAX + 1;
    }

    printf("\n---\n\nSorted:\n");

    for (i = 0; i < SIZE; i++)
        printf("%d\n", sorted[i]);


    return 0;
}
