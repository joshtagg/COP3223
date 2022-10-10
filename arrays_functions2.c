//Sarah Angell
//This program demonstrates the user of arrays
//as parameters. We will read values from a
//file into an array and calculate the average.

#include <stdio.h>

#define MAX 10

//function prototypes
void init(int numbers[MAX]);
void printArray(int numbers[MAX], int length);
void getValues(int numbers[MAX], int * length);
void average(int numbers[MAX], int length);

int main() {
    int numbers[MAX], length;

    init(numbers);

    getValues(numbers, &length);

    printArray(numbers, length);

    average(numbers, length);

    return 0;
}


//pre-conditions: numbers has been declared in main
//post-conditions: each element of numbers will be set to 0
void init(int numbers[MAX]) {
    int i;
    for(i = 0; i < MAX; i++)
        numbers[i] = 0;
    return;
}

//pre-conditions: numbers is an array of integers, length is the number of elements currently in use
//post-conditions: print all the active elements of the array
void printArray(int numbers[MAX], int length) {
    int i;
    for (i = 0; i < length; i++)
        printf("%d\t", numbers[i]);
    return;
}

//pre-conditions: numbers is an array of integers, length is the number of elements that will be populated
//post-conditions: ask the user for an input file
//                 this function reads files in the header format
void getValues(int numbers[MAX], int * length) {
    char filename[20];
    FILE * ifp = NULL;
    int i;

    while (ifp == NULL) {
        printf("What is the file name?\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");
    }

    fscanf(ifp, "%d", length);

    for (i = 0; i < (*length); i++)
        fscanf(ifp, "%d", &numbers[i]);

    fclose(ifp);
}

//pre-conditions: numbers is an array of integers, length is the number of elements currently in use
void average(int numbers[MAX], int length) {
    int i, sum = 0;
    float avg;

    for(i = 0; i < length; i++)
        sum += numbers[i];

    avg = sum / (float) length;

    printf("The average of these values is %.2f.\n", avg);

    return;
}




















