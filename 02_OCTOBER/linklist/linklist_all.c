#include<stdio.h>
#include<stdlib.h>
typedef struct node { int data; struct node *next; } NODE; // created type for node
void insert_last(NODE **head, int new_data) {
    NODE *newnode = (struct  node *)malloc(sizeof(NODE)); // allocate memory for new node
    newnode->data = new_data; // set data pointer
    newnode->next = NULL; // set an ending to latest node
    if (*head == NULL){ *head = newnode; } // set head if linglist is empty
    else {
        NODE *q = *head; // set head pointer to start of loop
        while (q->next != NULL) { q = q->next; } // find the last node of linklist
        q->next = newnode; // linked the new node to the end of the linked list
    }
}
void insert_begin(NODE **head, int new_data) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = new_data;
    newnode->next = *head;
    *head = newnode;
}
void delete(NODE **head, int new_data) {
    NODE *q = *head;
    NODE *prev;
    if (q->data == new_data) { *head = q->next; return; }
    while (q != NULL) {
        if (q->data == new_data) { break; }
        prev = q;
        q = q->next;
    }
    prev->next = q->next;
}
void insert_btw(NODE **head, int new_data) {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = new_data;
    int this_data;
    printf("insert the data you want to insert next to: ");
    scanf("%d", &this_data);
    NODE *q = *head;
    while (q != NULL) {
        if (q->data == this_data) { break; }
        q = q->next;
    }
    newnode->next = q->next;
    q->next = newnode;
}
void display( NODE *head) {
    NODE *q = head; // set head pointer to start of loop
    while (q != NULL) {
        printf("%d -> ", q->data);
        q = q->next;
    }
    printf("NULL\n");
}
int main() {
    int new_data, choice;
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head = NULL;
    while (1) {
        printf("1. Insert at end\t2. Insert at beginning\t3. Insert in between\t4. Delete\t5. Display\t6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the data to add at the end: ");
            scanf("%d", &new_data);
            insert_last(&head, new_data);
            break;
        case 2:
            printf("Enter the data to add at the beginning: ");
            scanf("%d", &new_data);
            insert_begin(&head, new_data);
            break;
        case 3:
            printf("Enter the data to add in betweeen: ");
            scanf("%d", &new_data);
            insert_btw(&head, new_data);
            break;
        case 4:
            printf("Enter the data you want to be deleted: ");
            scanf("%d", &new_data);
            delete(&head, new_data);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Wrong Option, DO it again!\n");
            break;
        }
    }
}