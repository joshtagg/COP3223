//Joshua Taggart

#include <stdio.h>

int main() {
    int i, cur_num;

    //can combine
    //FILE * ifp = fopen("input_sentinel.txt", "r");
    FILE * ifp;
    ifp = fopen("num_sentinel.txt", "r");

    fscanf(ifp, "%d", &cur_num);

    while (cur_num != 0) {
        //check to see if num is even
        if(cur_num % 2 == 0)
            printf("%d is even.\n", cur_num);
        else
            printf("%d is odd.\n", cur_num);

        fscanf(ifp, "%d", &cur_num);

    }

    fclose(ifp);

    return 0;
}
