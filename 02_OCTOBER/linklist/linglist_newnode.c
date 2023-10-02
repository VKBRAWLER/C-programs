#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void create (struct node *head, int new_data) {
        struct node *newnode, *q;
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = new_data;
        newnode->next = NULL;
        if (head == NULL) { head = newnode; }
        else { q = head;
            while (q->next != NULL) { q = q-> next; }
        q->next = newnode;
    }
}
#define MAX 5;
int main() {
    int new_data, i;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    // printf("%d %d", head->data, head);
    for (i=0; i < 5; i++) {
        scanf("%d", &new_data);
        create(head, new_data);
    }
    struct node *r;
    r = head->next;
    do {
        printf("%d -> ", r->data);
        r = r->next;
    } while (r != NULL);
    printf("NULL");
    return 0;
}