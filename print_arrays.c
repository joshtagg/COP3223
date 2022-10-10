//Sarah Angell
//This program demonstrates some basic arrays.
//We will declare, initialize, and print arrays.

#include <stdio.h>

int main() {
    float miles[10];
    int i;

    //initialize
    for (i = 0; i < 10; i++)
        miles[i] = i*2;

    //print forward
    for (i = 0; i < 10; i++)
        printf("Index %d: %.2f\n", i, miles[i]);

    printf("\n\n---\n\n");

    //print backward
    for (i = 9; i >= 0; i--)
        printf("Index %d: %.2f\n", i, miles[i]);

    return 0;
}
