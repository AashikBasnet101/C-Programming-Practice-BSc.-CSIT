//Tower of Hanoi (recursive)
#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    hanoi(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n-1, aux, to, from);
}

int main() {
    int n;
    printf("Number of disks: ");
    if (scanf("%d", &n)!=1) return 0;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
