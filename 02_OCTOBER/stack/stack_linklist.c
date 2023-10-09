#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} STACK;
int main() {
    STACK *stack = (STACK *) malloc(sizeof(STACK));
    int value, choice;
    while(1) {
        printf("\nENter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value you want to add: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Unknown choice %d\n", choice);
            break;
        }
    }
}