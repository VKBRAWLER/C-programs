// c. Write a C program to evaluate any postfix expression.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
// Structure to represent a stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};
// Function to initialize an empty stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}
// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
    else {
        printf("Stack overflow! Cannot push %d\n", value);
        exit(1); // Exit with an error code
    }
}
// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    else {
        printf("Stack underflow! Stack is empty\n");
        exit(1); // Exit with an error code
    }
}
// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, operand1, operand2;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
            // Convert character to integer
        }
        else
        {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Division by zero is not allowed\n");
                    exit(1); // Exit with an error code
                }
                push(&stack, operand1 / operand2);
                break;
            default:
                printf("Invalid operator: %c\n", postfix[i]);
                exit(1); // Exit with an error code
            }
        }
    }
    return pop(&stack);
}
int main()
{
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}