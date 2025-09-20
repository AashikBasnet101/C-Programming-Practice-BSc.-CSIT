//Stack using pointers and dynamic memory (push/pop/display)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push(Node **top, int val) {
    Node *n = malloc(sizeof *n);
    n->data = val;
    n->next = *top;
    *top = n;
}

int pop(Node **top) {
    if (!*top) { printf("Stack underflow\n"); return -1; }
    Node *t = *top; int v = t->data;
    *top = t->next; free(t); return v;
}

void display(Node *top) {
    printf("Stack: ");
    for (; top; top = top->next) printf("%d ", top->data);
    printf("\n");
}

int main() {
    Node *top = NULL;
    push(&top, 10); push(&top, 20); push(&top, 30);
    display(top);
    printf("Popped: %d\n", pop(&top));
    display(top);
    // free remaining
    while (top) pop(&top);
    return 0;
}
