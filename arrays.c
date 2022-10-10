//Sarah Angell
//This program demonstrates some operations on arrays.

#include <stdio.h>

int main() {

    int numbers[10];
    int i, header, min, max, sum, search, found = 0;
    float avg;
    FILE * ifp = fopen("numbers.txt", "r");

    fscanf (ifp, "%d", &header);

    for (i = 0; i < 10; i++) {
        fscanf(ifp, "%d", &numbers[i]);
    }
    //print the array
    for (i = 0; i < 10; i++) {
        printf("Index %d: %d\n", i, numbers[i]);
    }

    //calculate the average
    sum = 0;
    for(i = 0; i < 10; i++)
        sum += numbers[i];

    avg = sum / (float) header;
    //avg = sum / 10.0;

    printf("The average of these values is %.2f.\n", avg);

    //calculate min
    min = numbers[0];
    for (i = 1; i < 10; i++)
        if (numbers[i] < min)
            min = numbers[i];
    printf("The smallest value is %d.\n", min);

    //calculate max
    max = numbers[0];
    for (i = 1; i < 10; i++)
        if (numbers[i] > max)
            max = numbers[i];
    printf("The largest value is %d.\n", max);

    //search for a specific value
    printf("What value are you searching for?\n");
    scanf("%d", &search);

    for (i = 0; i < 10; i++) {
        if (numbers[i] == search)
            found = 1;
    }
    if (found == 1)
        printf("%d was in the number set!\n", search);
    else
        printf("Sorry, %d is not in the number set.\n", search);


    fclose(ifp);

    return 0;
}






