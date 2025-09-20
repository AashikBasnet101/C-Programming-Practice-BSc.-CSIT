//Longest substring without repeating characters (sliding window)
#include <stdio.h>
#include <string.h>

int longest_unique(const char *s) {
    int last[256]; for (int i=0;i<256;i++) last[i] = -1;
    int res = 0, start = 0;
    for (int i=0; s[i]; ++i) {
        start = start > last[(unsigned char)s[i]] + 1 ? start : last[(unsigned char)s[i]] + 1;
        last[(unsigned char)s[i]] = i;
        res = res > (i - start + 1) ? res : (i - start + 1);
    }
    return res;
}

int main() {
    char s[512];
    printf("String: ");
    if (!fgets(s, sizeof s, stdin)) return 0;
    if (s[strlen(s)-1]=='\n') s[strlen(s)-1]=0;
    printf("Longest unique len = %d\n", longest_unique(s));
    return 0;
}
