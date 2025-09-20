//N-Queens using backtracking (print one solution)
#include <stdio.h>
#include <stdlib.h>

int safe(int *board, int row, int col, int n) {
    for (int i=0;i<col;i++) if (board[i]==row || abs(board[i]-row)==abs(i-col)) return 0;
    return 1;
}

int solve(int *board, int col, int n) {
    if (col==n) return 1;
    for (int r=0;r<n;r++) {
        if (safe(board, r, col, n)) {
            board[col]=r;
            if (solve(board, col+1, n)) return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("N: ");
    if (scanf("%d", &n)!=1 || n<=0) return 0;
    int *board = malloc(n * sizeof *board);
    if (solve(board, 0, n)) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) printf(board[i]==j ? "Q " : ". ");
            printf("\n");
        }
    } else printf("No solution\n");
    free(board);
    return 0;
}
