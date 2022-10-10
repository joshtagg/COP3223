//Joshua Taggart
//This program calculates the cost owed for taking OJ

#include <stdio.h>

int main() {

    float initprice, price, total = 0;
    int initounces, ounces, times, i;

    printf("What is the weight (in oz.) of the original container of OJ?\n");
    scanf("%d", &initounces);

    printf("What is the cost of the original container of OJ in dollars?\n");
    scanf("%f", &initprice);

    price = initprice / initounces;

    printf("How many times did your roommate take your juice?\n");
    scanf("%d", &times);

    for(i = 0; i < times; i++) {

        printf("How much juice did your roommate take this time (in oz.)?\n");
        scanf("%d", &ounces);

        total = total + (price * ounces);

        if(total >= 10) {
            printf("Your roommate owes you $10.00.\n");
            total = total - 10;
        }

    }

    printf("Your roommate owes you $%.2f.\n", total);

    return 0;
}
