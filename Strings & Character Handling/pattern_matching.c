//Pattern matching (naive strstr)
#include <stdio.h>
#include <string.h>

int naive_search(const char *txt, const char *pat) {
    int n = strlen(txt), m = strlen(pat);
    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) if (txt[i+j] != pat[j]) break;
        if (j == m) return i;
    }
    return -1;
}

int main() {
    char t[256], p[256];
    printf("Text: "); scanf(" %[^\n]", t);
    printf("Pattern: "); scanf(" %[^\n]", p);
    int idx = naive_search(t, p);
    if (idx>=0) printf("Found at %d\n", idx); else printf("Not found\n");
    return 0;
}
