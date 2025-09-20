//Singly linked list with insert, delete, display

#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int val; struct Node *next; } Node;

void insert_end(Node **head, int v) {
    Node *n = malloc(sizeof *n); n->val = v; n->next = NULL;
    if (!*head) { *head = n; return; }
    Node *t = *head; while (t->next) t = t->next; t->next = n;
}

void delete_val(Node **head, int v) {
    Node *cur = *head, *prev = NULL;
    while (cur) {
        if (cur->val == v) {
            if (prev) prev->next = cur->next; else *head = cur->next;
            free(cur);
            printf("Deleted %d\n", v); return;
        }
        prev = cur; cur = cur->next;
    }
    printf("Not found\n");
}

void display(Node *h) {
    for (; h; h = h->next) printf("%d -> ", h->val);
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    insert_end(&head, 5); insert_end(&head, 10); insert_end(&head, 15);
    display(head);
    delete_val(&head, 10);
    display(head);
    // free
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
