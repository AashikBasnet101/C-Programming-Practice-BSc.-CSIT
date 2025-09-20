//Dynamically create 2D matrix and do matrix addition
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    printf("Rows Columns: ");
    if (scanf("%d %d", &r, &c) != 2) return 0;
    int **A = malloc(r * sizeof *A);
    int **B = malloc(r * sizeof *B);
    int **C = malloc(r * sizeof *C);
    for (int i = 0; i < r; ++i) {
        A[i] = malloc(c * sizeof **A);
        B[i] = malloc(c * sizeof **B);
        C[i] = malloc(c * sizeof **C);
    }
    printf("Enter A:\n");
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) scanf("%d", &A[i][j]);
    printf("Enter B:\n");
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) scanf("%d", &B[i][j]);
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) C[i][j] = A[i][j] + B[i][j];
    printf("A+B:\n");
    for (int i=0;i<r;i++) { for (int j=0;j<c;j++) printf("%d ", C[i][j]); printf("\n"); }
    for (int i=0;i<r;i++){ free(A[i]); free(B[i]); free(C[i]); }
    free(A); free(B); free(C);
    return 0;
}
