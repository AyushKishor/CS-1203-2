#include <stdbool.h>
#include <stdio.h>

#define N 4

// Utility function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

// Utility function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0; // backtracking
        }
    }

    return false;
}

bool solveNQ() {
    int board[N][N] = { {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0} };

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}

/* Explanation:

The isSafe function checks if a queen can be placed on board[row][col] without being attacked by another queen.
The solveNQUtil function is a recursive utility function to solve the N-Queen problem using backtracking. It mainly uses isSafe() to check if a queen can be placed in board[row][col]. It returns false if no placement is possible, otherwise, it returns true and prints the placement.
The solveNQ function solves the N-Queen problem using solveNQUtil(). If a solution exists, it prints the solution.
*/

