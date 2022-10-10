//Sarah Angell
//String example: Names

#include <stdio.h>
#include <string.h>

int main() {
    char fname[20], lname[20], full[41];

    printf("What is your first name?\n");
    scanf("%s", fname);

    printf("What is your last name?\n");
    scanf("%s", lname);

    strcpy(full, fname);
    strcat(full, " ");
    strcat(full, lname);

    printf("Your full name is %s.\n", full);
    printf("It has %d characters in it.\n", strlen(full) - 1);

    return 0;
}
