//Write a program in C for N-Queen Problem Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define N 8  
int board[N][N];
int solutionCount = 0;
bool isSafe(int row, int col) {
    int i, j;
    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;
    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;
    return true;
}
void printBoard() {
    printf("Solution %d:\n", ++solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(board[i][j] ? "Q " : ". ");
        printf("\n");
    }
    printf("\n");
}
void solveNQueens(int row) {
    if (row == N) {
        printBoard();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQueens(row + 1);
            board[row][col] = 0;  // Backtrack
        }
    }
}
int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    solveNQueens(0);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total solutions for %d-Queens: %d\n", N, solutionCount);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
