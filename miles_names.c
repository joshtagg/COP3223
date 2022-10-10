//Sarah Angell
// The purpose of this program is read
// from a file and print a bar chart with names

#include <stdio.h>

int main() {
    FILE * ifp = NULL, * ofp;
    char name[20], filename[20];
    int num_part, i, j, miles;

    //ifp = fopen("names.txt", "r");
    ofp = fopen("output.txt", "w");

    while (ifp == NULL) {
        printf("What is the name of the file?\n");
        scanf("%s", &filename);

        ifp = fopen(filename, "r");
    }

    fscanf(ifp, "%d", &num_part);

    for (i = 0; i < num_part; i++) {
        fscanf(ifp, "%s", &name);
        fscanf(ifp, "%d", &miles);

        fprintf(ofp, "%9s: ", name);

        for (j = 0; j < miles; j++)
            fprintf(ofp, "*");

        fprintf(ofp, "\n");
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
