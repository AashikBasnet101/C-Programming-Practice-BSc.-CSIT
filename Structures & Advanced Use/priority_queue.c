//Priority queue (min-heap) using array
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *h; int size, cap;
} MinHeap;

MinHeap* create(int cap) {
    MinHeap *m = malloc(sizeof *m); m->h = malloc(cap * sizeof *m->h); m->size=0; m->cap=cap; return m;
}
void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
void push(MinHeap *m, int v) {
    if (m->size==m->cap) { m->cap *=2; m->h = realloc(m->h, m->cap*sizeof *m->h); }
    int i = m->size++; m->h[i]=v;
    while (i && m->h[(i-1)/2] > m->h[i]) { swap(&m->h[i], &m->h[(i-1)/2]); i=(i-1)/2; }
}
int pop(MinHeap *m) {
    if (m->size==0) return -1;
    int root = m->h[0]; m->h[0] = m->h[--m->size];
    int i=0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < m->size && m->h[l] < m->h[smallest]) smallest = l;
        if (r < m->size && m->h[r] < m->h[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&m->h[i], &m->h[smallest]); i = smallest;
    }
    return root;
}

int main() {
    MinHeap *pq = create(8);
    push(pq, 5); push(pq, 3); push(pq, 10); push(pq, 1);
    printf("Pop: %d\n", pop(pq));
    printf("Pop: %d\n", pop(pq));
    free(pq->h); free(pq);
    return 0;
}
