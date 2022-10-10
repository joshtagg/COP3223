//Sarah Angell
//This program simulates one battle in the
//game of risk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int roll();
//a pass-by-reference function has references in the parameter list
//reference is a pointer or an array
void swap(int * x, int * y);

//a pass-by-value function has no references in the parameter list
int attack(int a1, int a2, int d1, int d2);

//main function
int main () {
    int a_roll1, a_roll2, d_roll1, d_roll2, temp, sum;
    srand(time(0));

    a_roll1 = roll();
    a_roll2 = roll();
    d_roll1 = roll();
    d_roll2 = roll();

    printf("The attackers rolls are %d and %d.\n", a_roll1, a_roll2);
    printf("The defenders rolls are %d and %d.\n", d_roll1, d_roll2);

    if (a_roll1 < a_roll2)
        swap(&a_roll1, &a_roll2);

    if (d_roll1 < d_roll2)
        swap(&d_roll1, &d_roll2);

    sum = attack(a_roll1, a_roll2, d_roll1, d_roll2);
    printf("The attackers defeated %d armies.\n", sum);

    return 0;
}

//pre-conditions: the random number generator is seeded
//post-condition: return a random value between 1 and 6
int roll() {
    return rand() % 6 + 1; //return random value from 1-6
}


//pre-conditions: x and y are pointers to integers
//post-conditions: swap the contents of x and y
void swap(int * x, int * y) {
    int temp = * x;
    *x = *y;
    *y = temp;
    return;
}

//pre-conditions: a1 and a2 are rolls from the attacker, a1 >= a2
//                d1 and d2 are rolls from the defender, d1 >= d2
//post-conditions: returns the number of armies the attacker defeated
int attack(int a1, int a2, int d1, int d2) {
    int total = 0;

    if (a1 > d1)
        total++;

    if (a2 > d2)
        total++;

    return total;
}

























