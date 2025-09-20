//Sparse matrix using triplets and addition
#include <stdio.h>
#include <stdlib.h>

typedef struct { int r,c,val; } Triplet;

Triplet* read_triplets(int *size) {
    int m; printf("Number of non-zero: "); scanf("%d", &m);
    Triplet *t = malloc(m * sizeof *t);
    for (int i=0;i<m;i++) { printf("r c val: "); scanf("%d %d %d", &t[i].r, &t[i].c, &t[i].val); }
    *size = m; return t;
}

Triplet* add_triplets(Triplet *A, int an, Triplet *B, int bn, int *rn) {
    Triplet *R = malloc((an+bn)*sizeof *R);
    int i=0, j=0, k=0;
    while (i<an && j<bn) {
        if (A[i].r < B[j].r || (A[i].r==B[j].r && A[i].c < B[j].c)) R[k++] = A[i++];
        else if (A[i].r > B[j].r || (A[i].r==B[j].r && A[i].c > B[j].c)) R[k++] = B[j++];
        else { int s = A[i].val + B[j].val; if (s!=0) { R[k].r=A[i].r; R[k].c=A[i].c; R[k++].val=s; } i++; j++; }
    }
    while (i<an) R[k++] = A[i++]; while (j<bn) R[k++] = B[j++];
    *rn = k; return R;
}

int main() {
    int an, bn;
    printf("Matrix A:\n"); Triplet *A = read_triplets(&an);
    printf("Matrix B:\n"); Triplet *B = read_triplets(&bn);
    int rn; Triplet *R = add_triplets(A,an,B,bn,&rn);
    printf("Result nonzeros: %d\n", rn);
    for (int i=0;i<rn;i++) printf("%d %d %d\n", R[i].r, R[i].c, R[i].val);
    free(A); free(B); free(R);
    return 0;
}
