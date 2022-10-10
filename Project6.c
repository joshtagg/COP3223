//Joshua Taggart
//Project 6
//The user will try to open the chest by choosing 7 keys.
//The keys must be in the correct order to open the chest.

#include <stdio.h>


int main() {
    FILE * ifp = NULL;
    char filename[20];
    // Answerlist is the array with the correct imported answers.
    // flag1 is a flag for the loop that finds duplicate keys.
    int answerlist[7], i, j, pos_dupe, flag1 = 0;
    // userkeys is the array that stores the user's selected key numbers.
    int userkeys[7];
    // no_dupe is the flag that sets to false if there is a duplicate.
    // seven_correct is the flag that breaks the final while loop when
    // the user finds the answer.
    int temp_samenum, num_correct_key = 0, no_dupe = 1, seven_correct = 0;
    int num_match = 0;


    // Get file name and open file
    while (ifp == NULL) {
        printf("What is the name of the file?\n");
        scanf("%s", &filename);
        ifp = fopen(filename, "r");
    }

    // Creates array with correct keys from file
    for(i = 0; i < 7; i++) {
        fscanf(ifp, "%d", &answerlist[i]);
    }

    // Initial instructions for user
    printf("-------------------------------\n");
    printf("To get to the treasure you'll have to figure out which of me ");
    printf("100 keys are used in the 7 locks of me treasure chest.\n\n");



    // This while loop will keep going until the user solves the order.
    while(seven_correct == 0) {

        // Prints initial prompt for user input
        // Will let user try again every time they are incorrect
        printf("Which keys will ye use?\n");
        for(i = 0; i < 7; i++)
            scanf("%d", &userkeys[i]);

        // This while loop manages finding duplicates in the user list.
        // If a duplicate is found, it will let the user know.
        while(flag1 == 0) {
            for(i = 0; i < 6; i++) {
                for(j = i + 1; j <= 6; j++) {
                    if(userkeys[i] == userkeys[j]) {
                        printf("You can only use each key once, matey!\n\n");
                        flag1 = 1;
                        no_dupe = 0;
                    }
                }
            }
            // This runs when a duplicate is detected
            if(flag1 == 1) {
                    break;
                }
            // This runs if no duplicate is detected
            else {
                no_dupe = 1;
                break;
            }

        }

        // Sets tracker of correct keys to 0 every time
        num_correct_key = 0;

        // This checks for numbers that are correct, +1 for each correct number
        // in the user's list
        for(i = 0; i < 7; i++) {
            temp_samenum = userkeys[i];

            for(j = 0; j < 7; j++) {
                if(temp_samenum == answerlist[j])
                    num_correct_key += 1;
            }
        }


        // This runs if none of the user's keys work.
        // This will also only run if there are no duplicates in user list.
        if(num_correct_key == 0 && no_dupe == 1) {
            printf("Hah! None of those keys work!\n\n");
            seven_correct = 0; //throwing this in here
            num_correct_key = 0;
        }
        // This runs if 0-6 keys are correct.
        // This will also only run if there are no duplicates in user list.
        else if(num_correct_key < 7 && no_dupe == 1) {
            printf("%d of those keys are correct, matey! But are they in the right order?\n\n", num_correct_key);
            seven_correct = 0;
            num_correct_key = 0;
        }
        // This runs if 7 keys are correct, either in order or not.
        // This will also only run if there are no duplicates in user list.
        else if(num_correct_key == 7 && no_dupe == 1) {
            // num_match is the number of keys that are in the correct order
            num_match = 0;
            // This checks if the 7 keys are in correct order
            for(i = 0; i < 7; i++) {
                if(userkeys[i] == answerlist[i])
                    num_match += 1;
            }
            // Print statement for when the chest is correctly opened
            if(num_match == 7) {
                printf("Arr! You've opened me treasure chest and found...\n");
                printf("A map! To the rest of me treasure on Treasure Island.\n");
                printf("Hahaha!\n");
                seven_correct += 1;
            }
            // This runs if it's the 7 correct keys but not in order
            else {
                printf("%d of those keys are correct, matey! But are they in the right order?\n\n", num_correct_key);
                num_correct_key = 0;
            }
        }

        // Breaks while loop when user solves order
        if(seven_correct == 1)
            break;

        // Resets the following flags for the duplicate loop
        flag1 = 0;
        no_dupe = 1;

    }

    return 0;
}




















