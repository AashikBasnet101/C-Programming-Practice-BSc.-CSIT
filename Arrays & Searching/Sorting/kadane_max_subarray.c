//Maximum subarray sum (Kadane’s algorithm)
#include <stdio.h>

int kadane(int a[], int n) {
    int max_ending = a[0], max_sofar = a[0];
    for (int i=1;i<n;i++) {
        max_ending = (a[i] > max_ending + a[i]) ? a[i] : max_ending + a[i];
        if (max_ending > max_sofar) max_sofar = max_ending;
    }
    return max_sofar;
}

int main() {
    int n; if (scanf("%d", &n)!=1) return 0;
    int a[n]; for (int i=0;i<n;i++) scanf("%d", &a[i]);
    printf("Max subarray sum = %d\n", kadane(a,n));
    return 0;
}
