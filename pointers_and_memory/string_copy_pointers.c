//Copy one string into another using only pointers
#include <stdio.h>

int main() {
    char src[256], dest[256];
    printf("Enter string: ");
    if (!fgets(src, sizeof src, stdin)) return 0;
    // remove newline
    char *p = src; while (*p && *p != '\n') p++; if (*p == '\n') *p = '\0';
    char *s = src, *d = dest;
    while ((*d++ = *s++)); // copies including terminating '\0'
    printf("Copied: %s\n", dest);
    return 0;
}
