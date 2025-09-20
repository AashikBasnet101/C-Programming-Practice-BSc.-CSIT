//Fibonacci using recursion with memoization
#include <stdio.h>
#include <stdlib.h>

long long fib_memo(int n, long long *memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
}

int main() {
    int n;
    printf("n: ");
    if (scanf("%d", &n)!=1 || n<0) return 0;
    long long *memo = malloc((n+1)*sizeof *memo);
    for (int i=0;i<=n;i++) memo[i] = -1;
    printf("Fib(%d) = %lld\n", n, fib_memo(n, memo));
    free(memo);
    return 0;
}
