#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print_list(struct node *head) {
    printf("[ ");
    while(head->next != NULL) {
        printf("%d\t", head->x);
        head = head->next;
    }
    printf("]\n");
}

struct node * insert_front(struct node *head, int a) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->x = a;
    p->next = head;
    return p;
}

struct node * free_list(struct node *head) {
    struct node *start = head;
    struct node *prev = start;
    while(prev != NULL) {
        prev = prev->next;
        free(head);
    }
    return start;
}

int main() {
    struct node head = {10, NULL};
    int i;
    for(; i < 5; i++) {
        insert_front(&head, i);
    }
    print_list(&head);
}
