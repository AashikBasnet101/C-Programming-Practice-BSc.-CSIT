//Check whether two strings are anagrams
#include <stdio.h>
#include <string.h>

int is_anagram(const char *a, const char *b) {
    int freq[256] = {0};
    for (; *a; a++) freq[(unsigned char)*a]++;
    for (; *b; b++) freq[(unsigned char)*b]--;
    for (int i=0;i<256;i++) if (freq[i]) return 0;
    return 1;
}

int main() {
    char a[256], b[256];
    printf("Enter 1: "); scanf(" %[^\n]", a);
    printf("Enter 2: "); scanf(" %[^\n]", b);
    printf(is_anagram(a,b) ? "Anagram\n" : "Not anagram\n");
    return 0;
}
