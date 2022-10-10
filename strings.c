//Sarah Angell
//This program demonstrates string functions
//from the string library string.h

#include <stdio.h>
#include <string.h>

int main() {
    char word1[20], word2[20];
    int length = 0, i;

    strcpy(word1, "hello");

    printf("%s!\n", word1);

    /*
    for(i = 0; word1[i] != '\0'; i++)
        length++;
    */

    length = strlen(word1);

    printf("The length of %s is %d.\n", word1, length);

    /*
    printf("\n\n");
    for(i = 0; i < 256; i++)
        printf("%d\t%c.\n", i, i);
    */

    printf("Please enter a string:\n");
    scanf("%s", word2); //array name doesnt need ampersand (&) because arrays are naturally already a reference
                        //you don't want to de-reference it by putting an ampersand on it

    if (strcmp(word1, word2) < 0) {
        printf("%s comes before %s.\n", word1, word2);
    }
    else if (strcmp(word1, word2) > 0)
        printf("%s comes before %s.\n", word2, word1);
    else
        printf("Both strings are %s.\n", word1);

    return 0;
}
