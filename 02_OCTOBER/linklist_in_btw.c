#include<stdio.h>
#include<stdlib.h>
struct node { int data; struct node *next; };
int insert_begin(struct node *head, int data);
int main() {
    int data, choice;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    while (1) {
        switch (choice) {
        case 1:
            scanf("%d", &data);
            insert_begin(head, data);
            break;
        case 2:
            scanf("%d", &data);
            insert_begin(head, data);
            break;
        case 3:
            display(head);
            break;
        default:
            exit(1);
            break;
        }
    }

}