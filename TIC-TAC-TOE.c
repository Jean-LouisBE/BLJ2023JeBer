#include <stdio.h>

void printBoard(char board[3][3]) {
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    printf("+--------------------------------+\n");
    printf("|    WELCOME TO TIC TAC TOE!     |\n");
    printf("+--------------------------------+\n\n");

    while (1) {
        printBoard(board);

        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;
        moves++;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (moves == 9) {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
