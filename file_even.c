//Joshua Taggart

#include <stdio.h>

int main() {
    int i, header, cur_value;

    //can combine
    //FILE * ifp = fopen("input.txt", "r");
    FILE * ifp;
    ifp = fopen("num.txt", "r");

    fscanf(ifp, "%d", &header);

    for(i=0; i<header; i++) {
        fscanf(ifp, "%d", &cur_value);

        //if num is even
        if (cur_value % 2 == 0)
            printf("%d is even.\n", cur_value);

        else
            printf("%d is odd.\n", cur_value);

    }

    fclose(ifp);

    return 0;
}
