/* Joshua Taggart
 * This program will analyze the temperatures for each month to determine
 * which months are appropriate given the temperature range
 */

#include <stdio.h>

int main() {
    FILE * ifp = NULL;
    char filename[20];
    int coldest_temp, hottest_temp, i, j, month_len, cur_max_month, max_month, percent_become_int;
    float percent_ran, cur_val;

    // Get file name and open file
    while (ifp == NULL) {
        printf("Please enter the name of the weather data file:\n");
        scanf("%s", &filename);
        ifp = fopen(filename, "r");
    }

    // Prompt questions
    printf("Tell me about your crew's preferred temperature for sailing:\n");
    printf("What is the coldest temperature they can sail in?\n");
    scanf("%d", &coldest_temp);
    printf("What is the hottest temperature they can sail in?\n");
    scanf("%d", &hottest_temp);

    // Loops 12 times for each month
    for (i = 0; i < 12; i++) {
        percent_ran = 0;
        fscanf(ifp, "%d", &month_len);

        // Loop calculates the percentage for each month
        for (j = 0; j < month_len; j++) {
            fscanf(ifp, "%f", &cur_val);
            if (cur_val <= hottest_temp && cur_val >= coldest_temp) {
                percent_ran = percent_ran + ((1.0 / (float) month_len) * 100);
            }
        }

        // Turns percent into whole number to not confuse
        // between the several 100 percents in the list.
        percent_become_int = percent_ran;

        // This if statement finds the max percent through the 12 months
        if (percent_become_int > cur_max_month) {
            cur_max_month = percent_become_int;
            max_month = i + 1;
        }


        printf("Month %d: %.1f percent of days in range.\n", i + 1, percent_ran);
    }

    printf("\nYou should leave for the Caribbean in month %d!\n", max_month);

    // Closes .txt file when the program is done running
    fclose(ifp);
    return 0;
}
