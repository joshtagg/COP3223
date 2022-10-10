//Joshua Taggart
//This program

#include <stdio.h>

#define MAX_CUSTOMERS 100

int main() {
    int numCommands, i, accounts[MAX_CUSTOMERS];
    int command, id, amount, j, ok;
    char filename[20];

    FILE * ifp;

    printf("What is the name of the file?\n");
    scanf("%s", &filename);

    ifp = fopen(filename, "r");

    for (i = 0; i < MAX_CUSTOMERS; i++)
        accounts[i] = 0;

    fscanf(ifp, "%d", &numCommands);

    for (i = 0; i < numCommands; i++) {
        fscanf(ifp, "%d", &command);
        if (command == 1) {
            fscanf(ifp, "%d %d", &id, &amount);
            accounts[id] += amount;
        }
        else if (command == 2) {
            fscanf(ifp, "%d %d", &id, &amount);
            accounts[id] -= amount;
        }
        else {
            ok = 1;
            for (j = 0; j < MAX_CUSTOMERS; j++) {
                if (accounts[j] < 0) {
                    printf("Customer %d, you owe $%d. Please pay immediately!\n", j, -accounts[j]);
                    ok = 0;
                }
            }
            if (ok)
                printf("All accounts are paid up to date!!!\n");
        }
    }
    fclose(ifp);

    return 0;
}
