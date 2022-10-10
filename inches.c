/* Joshua Taggart
 *This program calculates the number of inches in a mile
 */

//pre-processor directives
#include <stdio.h>


//constants
#define INCHES 12
#define FEET 5280

//main function
int main() {
    //variable declaration and intitialization
    //int inches_in_foot = 12;
    //int feet_in_mile = 5280;
    int inches_in_mile;

    //assignment statement
    //inches_in_mile = inches_in_foot * feet_in_mile;
    inches_in_mile = INCHES * FEET;

    //print the result
    printf("The number of inches in a mile is %d. \n", inches_in_mile);

    //end main function
    return 0;

}
