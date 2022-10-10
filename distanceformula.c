//Joshua Taggart
//Distance Formula

//included libraries
#include <stdio.h>
#include <math.h>

int main() {
    double X1, X2, Y1, Y2;
    double distance;

    printf("Enter X1 \n");
    scanf("%lf", &X1);

    printf("Enter X2 \n");
    scanf("%lf", &X2);

    printf("Enter Y1 \n");
    scanf("%lf", &Y1);

    printf("Enter Y2 \n");
    scanf("%lf", &Y2);

    distance = sqrt(pow(X2-X1, 2)+pow(Y2-Y1, 2));

    printf("\nThe distance is %lf. \n", distance);

    return 0;
}
