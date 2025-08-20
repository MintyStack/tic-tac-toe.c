// tic_tac_toe.c
// Simple 2-player Tic Tac Toe Game in C

#include <stdio.h>

char board[3][3]; // 3x3 board

// Initialize board with numbers 1-9
void initBoard() {
    int k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + k;
            k++;
        }
    }
}

// Print the game board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---+---+---\n");
    }
    printf("\n");
}

// Check if a player has won
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        // columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

// Check if board is full
int isFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

int main() {
    int player = 1, pos, row, col;
    char mark;

    initBoard();

    while (1) {
        printBoard();
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d (%c), enter your position (1-9): ", player, mark);
        scanf("%d", &pos);

        if (pos < 1 || pos > 9) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row = (pos - 1) / 3;
        col = (pos - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[row][col] = mark;

        if (checkWin()) {
            printBoard();
            printf("🎉 Player %d (%c) wins!\n", player, mark);
            break;
        } else if (isFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1; // switch turn
    }

    return 0;
}
