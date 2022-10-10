//Joshua Taggart
// the

#include <stdio.h>
#include <string.h>

int main() {
    char pass[20], passconfirm[20];

    printf("Please enter your password:    ");
    scanf("%s", pass);

    printf("\n\nPlease re-enter your password again:    ");
    scanf("%s", passconfirm);

    printf("\n\n");

    if (strcmp(pass, passconfirm) == 0) {
        printf("Both passwords are the same.\n");
    }
    else
        printf("Both passwords are not the same.\n");



}
