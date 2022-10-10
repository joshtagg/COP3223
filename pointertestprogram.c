#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setup(int *number);

int main() {
    int value, i;
    srand(time(0));
    /*
    int number = 5;

    printf("Original main number %d\n", number);

    setup(&number);

    printf("Lastly, Number in main %d", number);
    */
    //value = rand() % 2 + 1;

    //printf("num: %d", value);

    for(i = 0; i < 100; i++) {
        value = rand() % 60 + 10; //returns 1 or 2, skips 0
        printf("%d\n", value);
    }

    return 0;
}

setup(int *number) {
    printf("Enter number to replace number from main:\n");
    scanf("%d", number);
    //*number = 2;

    printf("Here is number inside pointer: %d\n", *number);

    return;
}
