#include<stdio.h>
#include<stdlib.h>
typedef struct node { int data; struct node *next; } NODE;
int main() {
    int new_data, choice;
    NODE *head = NULL;
    while(1) {
        printf("1. Insert at end\t2. Reverse");
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
        }
    }
}