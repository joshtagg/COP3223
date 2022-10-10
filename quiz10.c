//Joshua Taggart

#include <stdio.h>
#include <string.h>

#define MAX_LEN 14

long long convert(char word[], int length);
void printText(long long value, int length);

int main() {

    int choice, len;
    char filename[MAX_LEN], word[MAX_LEN];
    long long res, value;
    FILE * ifp;

    printf("Would you like to (1) encode or (2) decode?\n");
    scanf("%d", &choice);

    if (choice == 1) {

        //Get input file name.
        printf("Please enter the input file name, to encode.\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");

        //Convert each word, one by one.
        while(fscanf(ifp, "%s", word) != EOF) {

            len = strlen(word);
            res = convert(word, len);
            printf("%lld %d\n", res, len);
        }
        fclose(ifp);
    }
    else {

        //Get input file name.
        printf("Please enter the input file name, to decode.\n");
        scanf("%s", filename);
        ifp = fopen(filename, "r");

        //Convert each pair of numbers, one by one.
        while(fscanf(ifp, "%11d%d", &value, &len) != EOF) {
            printText(value, len);
        }
        fclose(ifp);
    }
    return 0;
}

long long convert(char word[], int length) {
    long long value = 0;
    int i;

    for(i = 0; i < length; i++)
        value = 26*value + (word[i]-'A');

    return value;
}

void printText(long long value, int length) {
    char word[MAX_LEN];
    int i;

    for(i = length-1; i >= 0; i--) {
        word[i] = (char)(value%26 + 'A');
        value /= 26;
    }
    word[length] = '\0';
    printf("%s\n", word);
    return;
}
