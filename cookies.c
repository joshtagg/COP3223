//Sarah Angell
//This program demonstrates the use of switch statements
//to simulate buying boxes of girl scout cookies

#include <stdio.h>

#define THINMINTS 3
#define SAMOAS 2.5
#define SHORTBREAD 2

int main() {
    //variable declaration
    int type, num_boxes = 0;
    float total;

    //print menu for the user
    printf("Available Girl Scout Cookies:\n");
    printf("\t1 - Thin Mints\n");
    printf("\t2 - Samoas\n");
    printf("\t3 - Shortbread\n");
    printf("Which would you like?\n");

    scanf("%d", &type);

    switch (type) {
        //Thin Mints case
        case 1:
            printf("Thin Mints are $%.2f per box.\n", THINMINTS);
            printf("How many boxes would you like?\n");
            scanf("%d", &num_boxes);
            total = num_boxes * THINMINTS;
            break;
        //Samoas case
        case 2:
            printf("Samoas are $%.2f per box.\n", SAMOAS);
            printf("How many boxes would you like?\n");
            scanf("%d", &num_boxes);
            total = num_boxes * SAMOAS;
            break;
        //Shortbread case
        case 3:
            printf("Shortbread are $%.2f per box.\n", SHORTBREAD);
            printf("How many boxes would you like?\n");
            scanf("%d", &num_boxes);
            total = num_boxes * SHORTBREAD;
            break;
        default:
            printf("Sorry, that was not a valid option.\n");
            total = 0
            break;
    }
    printf("Your total cost is $%.2f.\n", total);
    printf("Thank you for shopping!\n");

    return 0;
}
