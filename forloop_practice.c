//Joshua Taggart
//This program will take an integer from the user and use
//a for loop to print that many *s

#include <stdio.h>

int main() {
    int number, loop;
    char asterick = '*';

    printf("Type an integer here: ");
    scanf("%d", &number);

    for(loop = 0; loop < number; loop++) {
        printf("%c \n", asterick);
    }

    return 0;
}
