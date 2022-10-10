//Sarah Angell
//This program demonstrates that arrays
//are references. Any program that has
//an array as a parameter is a pass-by-reference
//function.

#include <stdio.h>

//function prototypes
void changeOne(int numbers[5]); //arrays are naturally references, changes made to array will be evident

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int i;

    for (i = 0; i < 5; i++)
        printf("%d\t", numbers[i]);

    printf("\n");

    changeOne(numbers);

    for (i = 0; i < 5; i++)
        printf("%d\t", numbers[i]);

    printf("\n");

    return 0;
}

void changeOne(int numbers[5]) {
    numbers[2] = 0;
    return;
}
