//Sarah Angell
//This program demonstrates the use of if statements and switch statements

#include <stdio.h>

int main() {
    int ans;

    printf("File Menu:\n");
    printf("\t1-New\n");
    printf("\t2-Open\n");
    printf("\t3-Save\n");
    scanf("%d", &ans);

    //if statements
    /*
    if (ans == 1)
        printf("New file...\n");
    else  if (ans == 2)
        printf("Open file...\n");
    else if (ans == 3)
        printf("Save file...\n");
    else
        printf("Not a valid option.\n");
    */

    //switch
    switch (ans) {
    case 1:
        printf("New file...\n");
        break;
    case 2:
        printf("Open file...\n");
        break;
    case 3:
        printf("Save file...\n");
        break;
    default:
        printf("Not a valid option.\n");
        break;

    }

    return 0;
}
