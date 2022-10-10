//Sarah Angell
//This program demonstrates a menu-driven
//program using the Girl Scout Cookies program
//and pass by value functions

#include <stdio.h>

//prototype
int menu();
float process(int cookie);
float buy(float price);
void end(float total);

int main() {
    int ans;
    float total = 0, price;

    ans = menu();

    while (ans != 4) {
        price = process(ans);

        if (price != 0.0)
            total += buy(price);

        ans = menu();
    }

    end(total);

    return 0;
}


//Pre-Conditions: none
//Post-Conditions: a menu will be printed,
//                 the user's choice will be returned
int menu() {
    int choice;

    printf("Available Girl Scout Cookies:\n");
    printf("\t1 - Thin Mints\n");
    printf("\t2 - Samoas\n");
    printf("\t3 - Shortbread\n");
    printf("\t4 - Quit\n");
    printf("Which would you like?\n");

    scanf("%d", &choice);

    return choice;
}

//Pre-Conditions: the user's choice of cookie is passed in
//                choice should be 1, 2, 3, or 4
//Post-Condition: the price of the cookie selected is returned
//                returns 0 if the choice is 4 or invalid.
float process(int cookie) {
    if (cookie == 1) {
        printf("Thin Mints are $3.50 per box.\n");
        return 3.5;
    }
    else if (cookie == 2) {
        printf("Samoas are $3.00 per box.\n");
        return 3.0;
    }
    else if (cookie == 3) {
        printf("Shortbreads are $2.50 per box.\n");
        return 2.5;
    }
    else if (cookie == 4)
        ;
    else {
        printf("Sorry that was not a valid option.\n");
    }


    return 0;
}

//Pre-conditions: Takes in price, the cost per box of cookie
//                Price cannot be zero
//Post-conditions: The user will be prompted for the total number
//                of boxes and a total for the transaction will be returned
float buy(float price) {
    float total;
    int boxes;


    printf("How many boxes would you like?\n");
    scanf("%d", &boxes);

    total = boxes * price;

    return total;

    //return boxes*price;
}

//Pre-conditions: Takes in the total that the user spent
//                May be zero
//Post-conditions: Prints ending message
void end(float total) {
    printf("Your total is $%.2f.\n", total);
    printf("Thank you for shopping!\n");
    return;
}











