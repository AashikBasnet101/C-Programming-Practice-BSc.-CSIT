//Caesar cipher encryption/decryption
#include <stdio.h>
#include <ctype.h>

void caesar(char *s, int k) {
    for (; *s; ++s) {
        if (isalpha((unsigned char)*s)) {
            char base = isupper((unsigned char)*s) ? 'A' : 'a';
            *s = (char)(base + ( (*s - base + k) % 26 + 26 ) % 26);
        }
    }
}

int main() {
    char text[512];
    int k;
    printf("Text: ");
    if (!fgets(text, sizeof text, stdin)) return 0;
    if (text[strlen(text)-1]=='\n') text[strlen(text)-1]=0;
    printf("Shift: "); scanf("%d", &k);
    caesar(text, k);
    printf("Encrypted: %s\n", text);
    caesar(text, -k);
    printf("Decrypted: %s\n", text);
    return 0;
}
