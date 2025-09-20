//Copy file contents without using fgets/fputs (use fgetc/fputc)

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) { printf("Usage: %s src dst\n", argv[0]); return 0; }
    FILE *src = fopen(argv[1], "rb"), *dst = fopen(argv[2], "wb");
    if (!src || !dst) { perror("fopen"); return 1; }
    int c;
    while ((c = fgetc(src)) != EOF) fputc(c, dst);
    fclose(src); fclose(dst);
    printf("Copied\n");
    return 0;
}
