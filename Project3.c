/* Joshua Taggart
 * This program runs a menu for buying used or new pirate gear
 * and calculates the total cost and average cost of the gear.
 */


// pre-processor directives
#include <stdio.h>

// These are the defined costs for used and new gear
#define NEW_COST 15
#define USED_COST 5


int main() {
    // Variable declaration
    // num_new_pur/num_used_pur stores the number of new/used gear purchased
    int menu_num, num_new_pur = 0, num_used_pur = 0, total_cost = 0;
    // avg_cost stores the average cost of the gear bought, num_gear stores the
    // total pieces of gear bought
    float avg_cost, num_gear = 0;

    // Initial print of the menu for the user
    printf("Welcome to the market!\n");
    printf("What would you like to do?\n");
    printf("\t1. Buy New Gear.\n");
    printf("\t2. Buy Used Gear.\n");
    printf("\t3. Quit\n");

    // This receives the user's menu number input
    scanf("%d", &menu_num);

    // This while loop runs if the user has not decided to exit the menu
    while (menu_num != 3) {

        // This switch statement handles the three menu options
        switch (menu_num) {
            // Buying new gear
            case 1:
                printf("\nHow many pieces of new gear would you like to buy?\n");
                scanf("%d", &num_new_pur);
                total_cost = total_cost + (num_new_pur * NEW_COST);
                break;
            // Buying used gear
            case 2:
                printf("\nHow many pieces of used gear would you like to buy?\n");
                scanf("%d", &num_used_pur);
                total_cost = total_cost + (num_used_pur * USED_COST);
                break;
            // Quit
            case 3:
                break;
            // This runs if the user typed an incorrect menu number
            default:
                printf("Sorry, %d is not a valid choice.\n", menu_num);
                break;
        } // end switch

        // Reprint menu each time for after the user makes a selection
        printf("\nWhat would you like to do?\n");
        printf("\t1. Buy New Gear.\n");
        printf("\t2. Buy Used Gear.\n");
        printf("\t3. Quit\n");

        scanf("%d", &menu_num);
    } // end while loop


    // If the user decides to buy no gear or exits the menu without purchasing
    // anything, this statement runs
    if (num_new_pur == 0 && num_used_pur == 0) {
        printf("Your total cost is %d gold pieces.\n", total_cost);
        printf("You obtained %d pieces of new gear and %d pieces of used gear.\n", num_new_pur, num_used_pur);
    } // end if statement

    // If the user has bought any number of gear and has exited the menu,
    // this else statement runs
    else {
        // calculate average cost of all gear purchased
        num_gear = num_new_pur + num_used_pur;
        avg_cost = total_cost / num_gear;

        // these statements print once the user is done with their purchases
        printf("Your total cost is %d gold pieces.\n", total_cost);
        printf("You obtained %d pieces of new gear and %d pieces of used gear.\n", num_new_pur, num_used_pur);
        printf("The cost per piece of gear is %.2f pieces of gold.\n", avg_cost);
        } // end else statement


    return 0;
}
