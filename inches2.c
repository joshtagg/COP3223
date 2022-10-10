/* Joshua Taggart
 *This program calculates the number of inches in a user-specified number of miles
 */

//pre-processor directives
#include <stdio.h>


//constants
#define INCHES 12
#define FEET 5280

//main function
int main() {
    //variable declaration and intitialization
    int inches_in_mile;
    float num_miles;

    //prompt user for information
    printf("How many miles?\n");
    scanf("%f", &num_miles);

    //assignment statement
    inches_in_mile = (INCHES * FEET * num_miles;

    //print the result
    printf("The number of inches in %.2f miles is %d. \n", num_miles, inches_in_mile);

    //end main function
    return 0;

}
