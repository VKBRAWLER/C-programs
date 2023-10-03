#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct Stack {
    int items[MAX_SIZE];
    int top;
} STACK;
void push (STACK *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {printf("stack is full\n"); return; }
    stack->items[++(stack->top)] = value;
}
void pop (STACK *stack) {
    if (stack->top == -1) {printf("stack is empty\n"); return; }
    --(stack->top);
}
void display (STACK *stack) {
    if (stack->top == -1) {printf("stack is empty\n"); return; }
    int i;
    for (i = 0; i <= stack->top; i++) {
        printf(" %d ", stack->items[i]);
    }
}
int main() {
    int value, choice;
    STACK *stack;
    stack->top = -1;
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
