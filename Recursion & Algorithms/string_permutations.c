//Generate all permutations of a string (recursion)
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }

void perm(char *s, int l, int r) {
    if (l == r) { printf("%s\n", s); return; }
    for (int i = l; i <= r; ++i) {
        swap(&s[l], &s[i]);
        perm(s, l+1, r);
        swap(&s[l], &s[i]); // backtrack
    }
}

int main() {
    char s[20];
    printf("Enter string: ");
    if (scanf("%19s", s)!=1) return 0;
    perm(s, 0, strlen(s)-1);
    return 0;
}
