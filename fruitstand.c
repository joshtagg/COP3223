//Sarah Angell
/* Fruit Stand Example
This program demonstrates the use of
pass by value functions */

#include <stdio.h>

#define COST .99

//function prototypes
void printChange(int cents);
int menu();
int buy();
float change(int num_fruits);
void status(int fruit, float cash);

int main() {
    float cash;
    int fruit = 0, cur_fruit, choice;

    printf("How much cash do you have?\n");
    scanf("%f", &cash);

    choice = menu();

    while (choice != 2) {
        if (cash < COST)
            printf("Sorry, you do not have enough money to buy fruit.\n");
        else {
            cur_fruit = buy();
            while (cur_fruit < 0) {
                printf("Sorry, that is not a valid amount of fruit.\n");
                cur_fruit = buy();
            }
            cash -= change(cur_fruit);
            fruit += cur_fruit;
        }
        choice = menu();
    }

    status(fruit, cash);

    return 0;
}


//pre-conditions: none
//post-conditions: prompt the user with a menu and return their response
int menu() {
    int ans;
    printf("Would you like to buy some fruit?\n");
    printf("1 - Yes\n");
    printf("2 - Leave\n");
    scanf("%d", &ans);
    return ans;
}

//pre-conditions: none
//post-conditions: ask the user how many fruits they want to buy
//                 return that value
int buy() {
    int num;
    printf("How many fruits would you like to buy?\n");
    scanf("%d", &num);
    return num;
}

//Pre-conditions: num_fruits non-negative
//Post-condition: tell the user the total for this transaction
//                ask the user how much they will pay
//                calculate and print their change
//                return the amount that the user spent
float change(int num_fruits) {
    float total = num_fruits * COST, cash;
    int change;

    printf("The cost of %d fruits is $%.2f.\n", num_fruits, total);
    printf("How much will you pay?\n");
    scanf("%f", &cash);

    change = cash*100 - total*100; //5.50 5.25  = 550-525 -> 25 cents change
    printf("Here is your change:\n");
    printChange(change);

    return total;


}


//Pre-conditions: cents is non-negative
//Post-conditions: print each coin of change
//                 Q - quarter, D - dime, N - nickel, P - penny
void printChange(int cents) {
    int i, quarters, dimes, nickels, pennies;

    quarters = cents / 25;
    cents = cents - quarters * 25;
    dimes = cents / 10;
    cents = cents - dimes * 10;
    nickels = cents / 5;
    cents = cents - nickels * 5;
    pennies = cents % 5;

    for(i = 0; i < quarters; i++)
        printf("Q");
    for(i = 0; i < dimes; i++)
        printf("D");
    for(i = 0; i < nickels; i++)
        printf("N");
    for(i = 0; i < pennies; i++)
        printf("P");

    printf("\n\n");

    return;
}

//pre-conditions: total number of fruit purchased (must be non-negative)
//                remaining cash (must be non-negative)
//post-condition: print the final status report
void status(int fruit, float cash) {
    printf("You purchased %d total fruits.\n", fruit);
    printf("You have $%.2f remaining.\n", cash);
    printf("Thank you for shopping!\n");
    return;
}







