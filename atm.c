//Sarah Angell
//This program simulates an atm
//it demonstrates pass-by-value and
//pass-by-reference functions

#include <stdio.h>

#define FAST 60

void menu();
void balance(int accnt_bal);
void deposit(int * accnt_bal);
void withdraw(int * accnt_bal);
void fastCash(int * accnt_bal);

int main() {
    int response, account;

    printf("Welcome to the COP 3223 ATM!\n");

    printf("What is your starting balance?\n");
    scanf("%d", &account);

    menu();
    scanf("%d", &response);
    printf("\n");



    while(response != 5) {
        switch(response) {
            case 1:
                withdraw(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                fastCash(&account);
                break;
            case 4:
                balance(account);
                break;
            default:
                printf("Sorry, that was not a valid option.\n");
                break;
        }

        menu();
        scanf("%d", &response);
        printf("\n");

    }

    printf("Thank you for using our ATM!\n");

    return 0;
}

//pre-conditions: none
//post-conditions: prints a menu
void menu() {
    printf("1 - Withdraw\n");
    printf("2 - Deposit\n");
    printf("3 - Fast Cash\n");
    printf("4 - View Account Balance\n");
    printf("5 - Quit\n");
    return;
}

//pre-conditions: takes in the user's current balance
//post-conditions: prints the user's current balance
void balance(int accnt_bal) {
    printf("Your current balance is %d.\n\n", accnt_bal);
}

//pre-conditions: accnt_bal is a pointer to the user's account balance
//post-condition: ask the user how much they want to withdraw
//                check the user's account
//                withdraw that amount if they have enough
void withdraw(int * accnt_bal) {
    int amount;

    printf("How much do you want to withdraw?\n");
    scanf("%d", &amount);

    if (amount > *accnt_bal) {
        printf("Sorry, you do not have that much in your account.\n");
    }
    else
        *accnt_bal = *accnt_bal - amount;

    return;
}

//pre-condition: accnt_bal is a pointer to the user's account
//post-condition: ask the user how much they want to deposit
//                add that amount to the user's account
void deposit(int * accnt_bal) {
    int amount;

    printf("How much do you want to deposit?\n");
    scanf("%d", &amount);

    *accnt_bal += amount;
    //*accnt_bal = *accnt_bal + amount;

    printf("\n");

    return;
}

//pre-conditions: accnt_bal is a pointer to the user's account
//post-conditions: check to see if they have $60 in the account
//                 if they do, withdraw that amount
void fastCash(int * accnt_bal) {
    if (*accnt_bal < FAST)
        printf("Sorry, you do not have enough money in your account.\n");
    else
        *accnt_bal -= FAST;

    printf("\n");

    return;
}
























