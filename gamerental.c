//Sarah Angell
//This program demonstrate explicit vs implicit nesting for If Statements

#include <stdio.h>

int main(){
    int age;

    printf("How old are you?\n");
    scanf("%d", &age);

    //explicit nesting
    /*
    if (age >= 10) {
        if (age >= 13) {
            if (age >= 18)
                printf("You can rent adult games!\n");
            else
                printf("You can rent teen games!\n");
        }
        else
            printf("You can rent 10+ games!\n");
    }
    else
        printf("You can only rent games that are for everyone.\n");
    */

    //implicit nesting
    if (age >= 18)
        printf("You can rent adult games!\n");
    else if (age >= 13)
        printf("You can rent teen games!\n");
    else if (age >= 10)
        printf("You can rent 10+ games!\n");
    else
        printf("You can only rent games that are for everyone.\n");

    printf("Enjoy renting games!\n");

    return 0;
}
