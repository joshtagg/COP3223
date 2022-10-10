#include <stdio.h>

int main() {

    int userkeys[7] = {7, 6, 5, 4, 3, 2, 1};
    //int userkeys[7] = {1, 2, 3, 4, 5, 6, 7};
    int keylist[7] = {1, 2, 3, 4, 5, 6, 7};
    int i, j;
    int temp;
    int num_correct = 0;
    /*
    for(i = 0; i < 7; i++) {
        temp = userkeys[i];
        for(j = 0; j < 7; j++) {
            if (temp == keylist[j]) {
                printf("YES, +1\n");
                num_correct += 1;
                printf("correct: %d\n", num_correct);
            }
        }

    }
    printf("num_correct is %d\n", num_correct);

    if (num_correct == 7) {
        printf("2 lists are the same\n");
    }
    else
        printf("NOT SAME\n");
    */

    for(i = 0; i < 7; i++) {
        if(userkeys[i] == keylist[i])
            num_correct += 1;
    }

    printf("num_correct: %d", num_correct);


    /*
    int length = sizeof(userkeys)/sizeof(userkeys[0]);
    printf("%d\n", length);


    for(i = 0; i < 6; i++) {
        for(j = i + 1; j <= 6; j++) {
            if(userkeys[i] == userkeys[j])
                printf("%d is a duplicate", userkeys[j]);
                //i = 0;

        }

    }
    */


    return 0;
}
