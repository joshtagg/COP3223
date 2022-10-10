

#include <stdio.h>

#define LENGTH 3

struct gnomelist {
    int length;
};

void GnomeSort(int gnomes[], int length);
void swap(int* ptrA, int* ptrB);

int main() {
    struct gnomelist gnomes[LENGTH];

    gnomes[0].length = 8;
    gnomes[1].length = 3;
    gnomes[2].length = 1;

    printf("gnome: %d\n", gnomes[0]);
    printf("gnome: %d\n", gnomes[1]);
    printf("gnome: %d\n", gnomes[2]);

    GnomeSort(gnomes, LENGTH);

    printf("\nSorted list: \n");

    printf("gnome: %d\n", gnomes[0]);
    printf("gnome: %d\n", gnomes[1]);
    printf("gnome: %d\n", gnomes[2]);


    return 0;
}

void GnomeSort(int gnomes[LENGTH], int length) {
    int pos = 1;

    while(pos < length) {
        if(gnomes[pos] >= gnomes[pos-1])
            pos++;

        else {
            swap(&gnomes[pos], &gnomes[pos-1]);

            if(pos > 1) {
                pos--;
            }
        }
    }
    return;
}

void swap(int* ptrA, int* ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    return;
}
