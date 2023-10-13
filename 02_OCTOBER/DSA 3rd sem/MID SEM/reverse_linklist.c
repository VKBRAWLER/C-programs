#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} NODE;

void reverseList(NODE** head) {
    NODE* prev = NULL;
    NODE* current = *head;
    NODE* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void printList(NODE* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    NODE* head = NULL;
    NODE* second = NULL;
    NODE* third = NULL;

    head = (NODE*)malloc(sizeof(NODE));
    second = (NODE*)malloc(sizeof(NODE));
    third = (NODE*)malloc(sizeof(NODE));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Original list: ");
    printList(head);

    reverseList(&head);

    printf("\nReversed list: ");
    printList(head);

    return 0;
}
