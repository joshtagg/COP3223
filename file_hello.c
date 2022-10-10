//Sarah Angell
//This program prints a message to an output file

#include <stdio.h>

int main() {
    FILE * ofp; //output file pointer
    ofp = fopen("output.txt", "w");

    fprintf(ofp, "Hello!\n");

    fclose(ofp);


    return 0;
}
