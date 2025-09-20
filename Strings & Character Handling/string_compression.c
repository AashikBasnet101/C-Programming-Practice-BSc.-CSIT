//String compression (run-length encoding)
#include <stdio.h>
#include <string.h>

int main() {
    char s[512];
    printf("String: ");
    if (!fgets(s, sizeof s, stdin)) return 0;
    int n = strlen(s); if (n && s[n-1]=='\n') s[--n]=0;
    char out[1024]; int oi=0;
    for (int i=0;i<n;) {
        char c = s[i]; int j = i;
        while (j < n && s[j]==c) j++;
        int count = j - i;
        out[oi++] = c;
        oi += sprintf(out+oi, "%d", count);
        i = j;
    }
    out[oi]=0;
    printf("Compressed: %s\n", out);
    return 0;
}
