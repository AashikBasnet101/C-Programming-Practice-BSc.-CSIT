//Merge two files into a third file
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) { printf("Usage: %s filename\n", argv[0]); return 0; }
    FILE *f = fopen(argv[1], "r"); if (!f) { perror("fopen"); return 1; }
    int c, lines=0, words=0, chars=0;
    int inword = 0;
    while ((c = fgetc(f)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) inword = 0;
        else if (!inword) { inword = 1; words++; }
    }
    fclose(f);
    printf("Lines=%d Words=%d Chars=%d\n", lines, words, chars);
    return 0;
}
