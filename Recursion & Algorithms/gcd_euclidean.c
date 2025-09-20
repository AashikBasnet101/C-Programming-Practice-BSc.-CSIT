//GCD (Euclidean recursion)
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a >= 0 ? a : -a;
    return gcd(b, a % b);
}

int main() {
    int a,b;
    printf("Enter two ints: ");
    if (scanf("%d %d", &a, &b)!=2) return 0;
    printf("GCD = %d\n", gcd(a,b));
    return 0;
}
