//Sarah Angell
//This program calculates a sum using a while loop

#include <stdio.h>

int main() {
    int num = 0, sum = 0, counter = 0;

    //Ask user for num
    printf("What is your number?\n");
    scanf("%d", &num);

    //This while loop adds all numbers from 0 to num
    while (counter <= num) {
        sum += counter;
        counter++;
    }

    //Print sum for user
    printf("The sum of numbers from 0 to %d is %d.\n", num, sum);

    return 0;
}
