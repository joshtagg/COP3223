/*Joshua Taggart
This program will ask the user for the radius of a hemisphere
and calculate the correct volume */

//pre-processor directives
#include <stdio.h>
#include <math.h>

//constants
#define PI 3.14159

//main function
int main() {
    //declare variables
    int r
    // int will only allow whole numbers
    float volume;

    //ask the user for input
    printf("What is the radius of the hemisphere?\n");
    scanf("%d", &r);

    //calculate the result
    volume = (2/3.0) * PI * pow(radius, 3);

    //print output
    printf("The volume of your hemisphere is %.2f \n", volume);

    //end of main
    return 0;
}
