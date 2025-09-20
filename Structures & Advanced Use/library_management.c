//Simple library management with structures & file handling (text file)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int id; char title[50]; char author[50]; int copies; } Book;

void add_book(const char *fname) {
    Book b;
    printf("ID Title Author Copies: ");
    scanf("%d %49s %49s %d", &b.id, b.title, b.author, &b.copies);
    FILE *f = fopen(fname, "a");
    if (!f) { perror("fopen"); return; }
    fprintf(f, "%d %s %s %d\n", b.id, b.title, b.author, b.copies);
    fclose(f);
}

void list_books(const char *fname) {
    Book b; FILE *f = fopen(fname, "r");
    if (!f) { perror("fopen"); return; }
    while (fscanf(f, "%d %49s %49s %d", &b.id, b.title, b.author, &b.copies)==4) {
        printf("%d %s %s %d\n", b.id, b.title, b.author, b.copies);
    }
    fclose(f);
}

int main() {
    const char *fn = "library.txt";
    int ch;
    printf("1 Add 2 List: "); if (scanf("%d", &ch)!=1) return 0;
    if (ch==1) add_book(fn); else if (ch==2) list_books(fn);
    return 0;
}
