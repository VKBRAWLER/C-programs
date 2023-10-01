#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insertstart (struct node *head, int new_data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = new_data;
    newnode->next = head->next;
    head->next = newnode;
}
void display (struct node *head) {
    struct node *q;
    q = head->next;
    // printf("head = %p\n", head);
    // printf("head pointing = %p\n", head->next);
    while (q != NULL) {
        printf("%d-> ", q->data);
        q = q->next;
    }
}
int main() {
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    int i, new_data;
    while (1) {
        printf("choice ");
        scanf("%d", &i);
        switch (i) {
        {
        case 1:
            scanf("%d", &new_data);
            insertstart(head, new_data);
            break;
        case 2:
            display(head);
            break;
        default:
            exit(1);
            break;
        }
    }
}
    return 0;
}