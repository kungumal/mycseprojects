#include <stdio.h>

// Function declarations
char getChoice(int player);
void determineWinner(char choice1, char choice2);

int main() {
    char player1Choice, player2Choice;
    
    printf("Rock-Paper-Scissors Game\n");
    
    // Get choices from both players
    player1Choice = getChoice(1);
    player2Choice = getChoice(2);

    // Determine and display the winner
    determineWinner(player1Choice, player2Choice);

    return 0;
}

// Function to get a player's choice
char getChoice(int player) {
    char choice;
    printf("Player %d, enter your choice (r for Rock, p for Paper, s for Scissors): ", player);
    scanf(" %c", &choice);  // Note the space before %c to ignore whitespace
    // Convert choice to lowercase to handle uppercase input
    if (choice >= 'A' && choice <= 'Z') {
        choice += 'a' - 'A';
    }
    // Validate input
    while (choice != 'r' && choice != 'p' && choice != 's') {
        printf("Invalid choice. Please enter r for Rock, p for Paper, or s for Scissors: ");
        scanf(" %c", &choice);
        // Convert choice to lowercase to handle uppercase input
        if (choice >= 'A' && choice <= 'Z') {
            choice += 'a' - 'A';
        }
    }
    return choice;
}

// Function to determine the winner
void determineWinner(char choice1, char choice2) {
    if (choice1 == choice2) {
        printf("It's a tie!\n");
    } else if ((choice1 == 'r' && choice2 == 's') ||
               (choice1 == 'p' && choice2 == 'r') ||
               (choice1 == 's' && choice2 == 'p')) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
}

