//Rotate array k times without extra space (reverse method)
#include <stdio.h>

void rev(int a[], int l, int r) {
    while (l < r) { int t = a[l]; a[l++] = a[r]; a[r--] = t; }
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k)!=2) return 0;
    int a[n]; for (int i=0;i<n;i++) scanf("%d", &a[i]);
    k = ((k % n) + n) % n;
    rev(a, 0, n-1);
    rev(a, 0, k-1);
    rev(a, k, n-1);
    for (int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
