/*Joshua Taggart
This program calculates the area of a trapezoid */

//pre-processor directives
#include <stdio.h>

//main function
int main() {
    //declare variables
    float a, b, height, area;
    //ask the user for input
    printf("What is the value of a?\n");
    scanf("%f", &a);

    printf("What is the value of b?\n");
    scanf("%f", &b);

    printf("What is the height?\n");
    scanf("%f", &height);

    //calculate the result
    area = (float) 1/2 * (a+b) + height;
    //print output
    printf("The area of your trapezoid is %.2f \n", area);

    //end of main
    return 0;

}
