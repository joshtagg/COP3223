//Sarah Angell
//Pointer Examples

#include <stdio.h>

int main() {
    int a = 7;
    int * p = &a;

    printf("A = %d\n\n", a);

    *p = 3;

    printf("A = %d\n\n", a);

    return 0;
}
