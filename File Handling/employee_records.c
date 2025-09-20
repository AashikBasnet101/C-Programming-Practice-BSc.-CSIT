//Maintain employee records in a binary file (add, display, search)
#include <stdio.h>
#include <string.h>

typedef struct { int id; char name[50]; double salary; } Emp;

void add(const char *fn) {
    Emp e; printf("ID Name Salary: "); scanf("%d %49s %lf", &e.id, e.name, &e.salary);
    FILE *f = fopen(fn, "ab"); if (!f) { perror("fopen"); return; }
    fwrite(&e, sizeof e, 1, f); fclose(f);
}

void list(const char *fn) {
    Emp e; FILE *f = fopen(fn, "rb"); if (!f) { perror("fopen"); return; }
    while (fread(&e, sizeof e, 1, f)==1) printf("%d %s %.2f\n", e.id, e.name, e.salary);
    fclose(f);
}

void search(const char *fn, int id) {
    Emp e; FILE *f = fopen(fn, "rb"); if (!f) { perror("fopen"); return; }
    while (fread(&e, sizeof e, 1, f)==1) if (e.id == id) { printf("%d %s %.2f\n", e.id, e.name, e.salary); fclose(f); return; }
    printf("Not found\n"); fclose(f);
}

int main() {
    const char *fn = "emps.bin"; int ch;
    printf("1 Add 2 List 3 Search: "); scanf("%d", &ch);
    if (ch==1) add(fn);
    else if (ch==2) list(fn);
    else if (ch==3) { int id; printf("ID: "); scanf("%d", &id); search(fn, id); }
    return 0;
}
