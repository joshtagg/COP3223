/* Joshua Taggart
 * This program demonstrates the pseudo-random number generator
 */

//pre-processor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 //Main function
int main() {
    srand(time(0));

    int num = rand() % 100; //random value from 0-99
    // num = rand() % 100 + 1; //random value from 1-100
    int num2 = rand();
    int num3 = rand() % 250;

    printf("Our random number is %d.\n", num);
    printf("%d\n%d\n", num2, num3);

    return 0;
}
