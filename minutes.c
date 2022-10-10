/* Joshua Taggart
This program calculates the number of minutes in a day
*/

//pre-processor directives
#include <stdio.h>

//main function
int main() {
    //variable declaration and intitialization
    int minutes_in_hour = 60;
    int hours_in_day = 24;
    int minutes_in_day;

    //assignment statement
    minutes_in_day = minutes_in_hour * hours_in_day;

    //print result
    printf("The number of minutes in a day is %d. \n", minutes_in_day);

    //end main function
    return 0;





}
