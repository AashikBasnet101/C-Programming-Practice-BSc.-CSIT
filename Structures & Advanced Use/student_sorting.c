//Student database and sort by marks (structures)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { char name[50]; int roll; float marks; } Student;

int cmp(const void *p, const void *q) {
    const Student *a = p, *b = q;
    if (a->marks < b->marks) return 1;
    if (a->marks > b->marks) return -1;
    return 0;
}

int main() {
    int n; printf("n: "); if (scanf("%d", &n)!=1) return 0;
    Student *s = malloc(n * sizeof *s);
    for (int i=0;i<n;i++) {
        printf("Name Roll Marks: ");
        scanf(" %49[^\n] %d %f", s[i].name, &s[i].roll, &s[i].marks);
    }
    qsort(s, n, sizeof *s, cmp);
    printf("Sorted by marks desc:\n");
    for (int i=0;i<n;i++) printf("%s %d %.2f\n", s[i].name, s[i].roll, s[i].marks);
    free(s);
    return 0;
}
