/* Joshua Taggart
 * This program prints out how tall the user is
 */


#include <stdio.h>
int main() {
    //variable declaration
    int total_inches, inches, feet;

    //prompt user for input information
    printf("How tall are you in inches? \n");
    scanf("%d", &total_inches);

    //calculations
    feet = total_inches / 12;
    inches = total_inches % 12;

    //output results
    printf("You are %d feet and %d inches tall!\n", feet, inches);

    return 0;
  }
