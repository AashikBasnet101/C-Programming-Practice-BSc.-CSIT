//Student grading and store results in a text file

#include <stdio.h>

int main() {
    const char *fn = "grades.txt";
    int n; printf("Number of students: "); if (scanf("%d", &n)!=1) return 0;
    FILE *f = fopen(fn, "w"); if (!f) { perror("fopen"); return 1; }
    for (int i=0;i<n;i++) {
        char name[50]; int marks;
        printf("Name Marks: "); scanf("%49s %d", name, &marks);
        char grade = (marks >= 90) ? 'A' : (marks >= 80) ? 'B' : (marks >= 70) ? 'C' : (marks >= 60) ? 'D' : 'F';
        fprintf(f, "%s %d %c\n", name, marks, grade);
    }
    fclose(f);
    printf("Saved to %s\n", fn);
    return 0;
}
