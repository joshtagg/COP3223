//Sarah Angell
//String Example: Letter Frequency

#include <stdio.h>
#include <string.h>

#define NUMWORDS 10
#define MAXLEN 20

int main() {
    FILE * ifp = NULL;
    char words[NUMWORDS][MAXLEN];
    char filename[MAXLEN];
    int freq[26], i, j;

    //open the file
    while(ifp == NULL) {
        printf("What is the name of the file?\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");
    }

    //get the words from the file
    for(i = 0; i < NUMWORDS; i++)
        fscanf(ifp, "%s", words[i]);

    fclose(ifp);

    //initialize frequency array
    for(i = 0; i < 26; i++)
        freq[i] = 0;

    //traverse words array and count the frequency of each letter
    for(i = 0; i < NUMWORDS; i++) {
        for(j = 0; j < strlen(words[i]); j++)
            freq[tolower(words[i][j]) - 'a']++;      //lower case i'th word, j'th letter
    }

    //print frequencies
    printf("Letter\tFrequency\n");
    for(i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            printf("%c\t%d\n", i+'a', freq[i]);
            for(j = 0; j < freq[i]; j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
