//Sarah Angell
//This program uses both input and output files
//to print how many miles each participant ran

#include <stdio.h>

int main() {
    FILE * ifp, * ofp;
    int num_part, i, j, cur_val;

    ifp = fopen("input.txt", "r");
    ofp = fopen("output.txt", "w");

    fscanf(ifp, "%d", &num_part);

    for(i = 0; i < num_part; i++) {
        fscanf(ifp, "%d", &cur_val);
        fprintf(ofp, "Person %d: ", i+1);

        for(j = 0; j < cur_val; j++) {
            fprintf(ofp, " * ");
        }
        fprintf(ofp, "\n");



    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
