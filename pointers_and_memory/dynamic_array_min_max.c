//Dynamically allocate array of n integers and find max/min
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc(n * sizeof *a);
    if (!a) { perror("malloc"); return 1; }
    for (int i = 0; i < n; ++i) { printf("a[%d]: ", i); scanf("%d", &a[i]); }
    int max = a[0], min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    printf("Max = %d, Min = %d\n", max, min);
    free(a);
    return 0;
}
