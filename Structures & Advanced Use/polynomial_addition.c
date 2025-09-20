//Add two polynomials using linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct Term { int coeff, pow; struct Term *next; } Term;

Term* newTerm(int c, int p) { Term *t = malloc(sizeof *t); t->coeff=c; t->pow=p; t->next=NULL; return t; }

void append(Term **h, int c, int p) {
    Term *t = newTerm(c,p);
    if (!*h) { *h=t; return; }
    Term *cur=*h; while (cur->next) cur=cur->next; cur->next=t;
}

Term* add(Term *a, Term *b) {
    Term *res = NULL;
    while (a && b) {
        if (a->pow == b->pow) { append(&res, a->coeff + b->coeff, a->pow); a=a->next; b=b->next; }
        else if (a->pow > b->pow) { append(&res, a->coeff, a->pow); a=a->next; }
        else { append(&res, b->coeff, b->pow); b=b->next; }
    }
    while (a) { append(&res, a->coeff, a->pow); a=a->next; }
    while (b) { append(&res, b->coeff, b->pow); b=b->next; }
    return res;
}

void printPoly(Term *h) {
    for (; h; h = h->next) printf("%+d x^%d ", h->coeff, h->pow);
    printf("\n");
}

int main() {
    // Example: create 2 polynomials
    Term *p1 = NULL, *p2 = NULL;
    append(&p1, 5, 3); append(&p1, 4, 1); append(&p1, 2, 0); // 5x^3 +4x +2
    append(&p2, 3, 3); append(&p2, -4, 1); append(&p2, 7, 0); // 3x^3 -4x +7
    Term *sum = add(p1, p2);
    printPoly(sum);
    return 0;
}
