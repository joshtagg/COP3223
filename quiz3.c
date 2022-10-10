//Joshua Taggart
//This program will correctly calculate the price of the orange juice
//the user is buying based on the Buy One Get One sale.

#include <stdio.h>

//main function
int main() {
    int cartons;
    float price, total;

    //prompt user for input information
    printf("What is the cost of one container of OJ in dollars?\n");
    scanf("%f", &price);

    printf("How many containers are you buying?\n");
    scanf("%d", &cartons);

    //if even
    if(cartons % 2 == 0)
        total = (cartons / 2) * price;
    //if odd
    else
        total = ((cartons / 2) * price) + price;

    printf("The total cost is $%.2f.\n", total);

    return 0;


}
