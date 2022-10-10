//Sarah Angell
//String Example: Sorting Books

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBOOKS 10
#define MAXLEN 80

void readbooks(char words[][MAXLEN]);
void printbooks(char words[][MAXLEN]);
void sort(char words[][MAXLEN]);
int maxlength(char words[][MAXLEN]);

int main() {
    char books[NUMBOOKS][MAXLEN];

    //gets the book titles
    readbooks(books);

    //prints an unsorted list
    printbooks(books);

    printf("\n\n---\n\n");

    //sort the books
    sort(books);

    printbooks(books);

    maxlength(books);

    return 0;
}


//pre-conditions: words is already declared
//post-conditions: reads in book titles from a file
//                 and stores them in words
void readbooks(char words[][MAXLEN]) {
    char filename[20];
    FILE * ifp = NULL;
    int i;

    while(ifp == NULL) {
        printf("What file stores the book titles?\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");
    }

    for(i = 0; i < NUMBOOKS; i++)
        fscanf(ifp, "%s", words[i]);

    return;
}


//pre-conditions: words is an array of strings already declared and initialized
//prost-conditions: prints the contents of words
void printbooks(char words[][MAXLEN]) {
    int i;

    for(i = 0; i < NUMBOOKS; i++)
        printf("%s\n", words[i]);

    return;
}



// Uses an insertion sort to sort the data in the array words. Lenth
// is the number of titles stored in words.
void sort(char words[][MAXLEN]) {
    int i, j;
    char temp[MAXLEN];
    // Loop through each element, inserting it into its proper location.
    for(i = 1; i < NUMBOOKS; i++) {
        j = 1;
        // Continue swapping elements as long as the current element is not
        // in the right location. Note the use of strcpy.
        while (j > 0 &&strcmp(words[j], words[j-1]) < 0) {
            //swap j and j-1
            strcpy(temp, words[j]);
            strcpy(words[j], words[j-1]);
            strcpy(words[j-1], temp);

            j--;
        }
    }
}

//pre-conditions: words is a sorted list of book titles
//post-conditions: find the longest book title and print it and the length
int maxlength(char words[][MAXLEN]) {
    int i, j, curlen, max = 0, row = 0;

    for(i = 0; i < NUMBOOKS; i++) {
        curlen = 0;
        for(j = 0; j < strlen(words[i]); j++)
            if(isalpha(words[i][j]))
                curlen++;

        if(curlen > max) {
            max = curlen;
            row = i;
        }
    }

    printf("The longest title is %s with %d characters.\n", words[row], max);

    return max;
}

































