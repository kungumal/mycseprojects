#include <stdio.h>

// Global variables for the Tic-Tac-Toe board
char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board with numbers
void initializeBoard() {
    int i, j, count = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = count + '0'; // Convert integer to character
            count++;
        }
    }
}

// Function to display the board
void displayBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to switch the player
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

// Function to mark a cell on the board
int markBoard(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return 1;
    }
    return 0;
}

// Function to check for a win or a tie
int checkWin() {
    int i;
    // Check rows and columns
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

// Function to check for a tie
int checkTie() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return 1;
}

int main() {
    int position;
    int validMove;
    int gameOver = 0;

    // Initialize and display the board
    initializeBoard();
    displayBoard();

    // Main game loop
    while (!gameOver) {
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &position);

        validMove = markBoard(position);
        if (!validMove) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Display the updated board
        displayBoard();

        // Check if the current player won
        if (checkWin()) {
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if (checkTie()) {
            printf("It's a tie!\n");
            gameOver = 1;
        } else {
            switchPlayer();
        }
    }

    return 0;
}

