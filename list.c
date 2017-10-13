#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print_list(struct node *head) {
    printf("[ ");
    while(head->next != NULL) {
        printf("%d,", head->x);
        head = head->next;
    }
    printf("%d ]\n", head->x);
}

struct node * insert_front(struct node *head, int a) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->x = a;
    p->next = head;
    return p;
}

struct node * free_list(struct node *head) {
    struct node *start = head;
    while(start != NULL) {
        start = start->next;
        free(start);
    }
    return head;
}

int main() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->x = 10;
    int i;
    for(; i < 5; i++) {
        head = insert_front(head, i);
    }
    struct node *nex = head->next;
    print_list(head);
    free_list(head);
}
