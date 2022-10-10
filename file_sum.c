/* Sarah Angell
This program reads values from a file
and adds them together
*/

#include <stdio.h>

int main() {
    FILE * ifp; //input file pointer
    int i, header, cur_value, sum = 0;

    ifp = fopen("input.txt", "r");

    fscanf(ifp, "%d", &header);

    for(i=0; i<header; i++) {
        fscanf(ifp, "%d", &cur_value);
        printf("%d\n", cur_value);
        sum += cur_value;
        //sum = sum + cur_val
        //sum = 0 + 150 + 136 + 178 + 200 + 189

    }

    printf("The sum of the numbers in the file are %d.\n", sum);

    fclose(ifp);

    return 0;
}
