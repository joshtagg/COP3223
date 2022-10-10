//Fill in your own header comment

#include <stdio.h>

#define SIZE 3

//Function Prototypes - DO NOT CHANGE THESE
void initialize(char board[SIZE][SIZE]);
void print_board(char board[SIZE][SIZE]);
int is_winner(char board[SIZE][SIZE]);
int is_full(char board[SIZE][SIZE]);
int check_move(char board[SIZE][SIZE], int x, int y);

//Main Function - This is already set up to work with the functions
int main() {
    //Declare necessary variables
    char board[SIZE][SIZE];
    int turn = 2, x, y;
    char play;

    //Initialize the game board
    initialize(board);

    //Information for the users
    printf("Player 1 will be X.\nPlayer 2 will be O.\n");

    //Alternate turns for the users until the board is full
    while (!is_full(board)) {
        //Set user's turn
        if (turn == 2) {
            turn = 1;
            play = 'X';
        }
        else {
            turn = 2;
            play = 'O';
        }

        //Announce whose turn it is
        printf("It is player %d's turn.\n", turn);

        //Print board
        print_board(board);

        //Ask user for their move
        printf("Where would you like to go?\t X Y\n");
        scanf("%d %d", &x, &y);

        //Verify the move is valid
        while (!check_move(board, x-1, y-1)) {
            printf("Sorry, that move was not valid.\n");
            printf("Where would you like to go?\t X Y\n");
            scanf("%d %d", &x, &y);
        }

        //Put user's move on the board
        board[y-1][x-1] = play;

        //Check to see if there is a winner
        if (is_winner(board)) {
            break;
        }
    }

    //Print the board a final time
    print_board(board);

    return 0;
}

/* Initialize Function
 * Pre-Condition:  This function takes in a SIZExSIZE board
 * Post-Condition: This function initializes the board
 *
 * Instructions: In this function, you will need to set
 * every index on the board to '-'
 */
void initialize(char board[SIZE][SIZE]) {
    int i, j;

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            board[i][j] = '-';

    return;
}

/* Print Function
 * Pre-Condition:  This function takes in a SIZExSIZE board
 * Post-Condition: This function prints the board
 *
 * Instructions: In this function, you will need to
 * print the contents of the board for the user to see.
 */
void print_board(char board[SIZE][SIZE]) {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            printf("\t%c", board[i][j]);
        printf("\n");
    }
    return;
}

/* Winner Function
 * Pre-Condition:  This function takes in a SIZExSIZE board
 * Post-Condition: This function will return a 1 if there is
 * winner and 0 otherwise
 *
 * Instructions: In this function, you will need to check each
 * row, column and diagonal to see if all three in that direction
 * are equal to each other and not equal to the initialization character.
 *
 * If there is a winner, print out whether it is Player 1 (X) or
 * Player 2 (O) and return 1.
 *
 * If there is not a winner yet, return 0.
 */
int is_winner(char board[SIZE][SIZE]) {
    int i, j, winner = 0, player = 0;
    char start;

    //check rows
    for(i = 0; i < SIZE; i++) {
        winner = 1;
        start = board[i][0];

        for(j = 1; j < SIZE; j++)
            if(board[i][j] != start || board[i][j] == '-')
                winner = 0;

        if(winner == 1)
            if(start == 'X') {
                printf("Player 1 has won the game!\n");
                return 1;
            }
            else {
                printf("Player 2 has won the game!\n");
                return 1;
            }
    }

    //check columns
    for(i - 0; i < SIZE; i++) {
        winner = 1;
        start = board[0][i];

        for(j = 1; j < SIZE; j++)
            if(board[j][i] != start || board[j][i] == '-')
                winner = 0;

        if(winner == 1)
            if(start == 'X') {
                printf("Player 1 has won the game!\n");
                return 1;
            }
            else {
                printf("Player 2 has won the game!\n");
                return 1;
            }
    }

    //check first diagonal
    winner = 1;
    start = board[0][0];
    for(i = 1; i < SIZE; i++)
        if(board[i][i] != start || board[i][i] == '-')
            winner = 0;

    if(winner == 1)
        if(start == 'X') {
            printf("Player 1 has won the game!\n");
            return 1;
        }
        else {
            printf("Player 2 has won the game!\n");
            return 1;
        }

    //check second diagonal
    winner = 1;
    start = board[0][SIZE-1];
    for(i = 1; i < SIZE; i++)
        if(board[i][SIZE-i-1] != start || board[i][SIZE-i-1] == '-')
            winner = 0;

    if(winner == 1)
        if(start == 'X') {
            printf("Player 1 has won the game!\n");
            return 1;
        }
        else {
            printf("Player 2 has won the game!\n");
            return 1;
        }

    return 0;
}

/* Full Function
 * Pre-Condition:  This function takes in a SIZExSIZE board
 * Post-Condition: This function will return a 1 if the board
 * if full and 0 otherwise
 *
 * Instructions: One of the easier methods of solving this problem
 * is to look through the board and return a 0 if any empty spaces are
 * found.  Empty spaces are denoted by the initialization character '-'.
 *
 * Return a 1 if no empty spaces are found.
 */
int is_full(char board[SIZE][SIZE]) {
    int i, j;

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            if(board[i][j] == '-')
                return 0;

    return 1;
}

/* Check Function
 * Pre-Condition:  This function takes in a SizexSize board, and two
 * integers x and y that represent the user's intended move
 * Post-Condition: This function returns a 1 if the user's intended
 * move is valid and 0 otherwise.
 *
 * Instructions: In this function, you need to verify that x and y
 * are valid input.  Check that they represent a correct index for
 * the board; that is, both numbers are between 1 and SIZE-1.  Then, check
 * that the space intended by x and y has not already been played.
 */
int check_move(char board[SIZE][SIZE], int x, int y) {
    if (x < 0 || x >= SIZE)
        return 0;

    if(y < 0 || y >= SIZE)
        return 0;

    if (board[y][x] != '-')
        return 0;

    return 1;

}
















