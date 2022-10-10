/*Sarah Angell
This program prints out a series of numbers in the following patter:
4 4 4 4
3 3 3
2 2
1
*/

#include <stdio.h>

int main() {
    int n = 1, i, j;

    for(i = 4; i >= n; i--) {
        for (j = 1; j <= i; j++)
            printf("%d", i);
        printf("\n");
    }

    return 0;
}
