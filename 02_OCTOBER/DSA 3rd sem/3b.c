#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Include ctype.h for isalnum

#define MAX_SIZE 100

// Structure to represent a stack of characters
struct CharStack {
    char items[MAX_SIZE];
    int top;
};

// Initialize the character stack
void initialize(struct CharStack *stack) {
    stack->top = -1;
}

// Check if the character stack is empty
bool isEmptyCharStack(struct CharStack *stack) {
    return (stack->top == -1);
}

// Check if the character stack is full
bool isFullCharStack(struct CharStack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Push a character onto the character stack
void pushChar(struct CharStack *stack, char value) {
    if (isFullCharStack(stack)) {
        printf("Character stack is full. Cannot push %c.\n", value);
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Pop a character from the character stack
char popChar(struct CharStack *stack) {
    if (isEmptyCharStack(stack)) {
        printf("Character stack is empty. Cannot pop.\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Get the top character from the character stack without popping it
char peekChar(struct CharStack *stack) {
    if (isEmptyCharStack(stack)) {
        printf("Character stack is empty. Cannot peek.\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// Function to check if a character is an operator (+, -, *, /, ^)
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int getOperatorPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert an infix expression to a postfix expression
void converter(char infix[], char postfix[]) {
    struct CharStack opStack;
    initialize(&opStack);
    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) { // Use isalnum to check if a character is an alphanumeric character
            postfix[postfixIndex++] = currentChar;
        } else if (currentChar == '(') {
            pushChar(&opStack, currentChar);
        } else if (currentChar == ')') {
            while (!isEmptyCharStack(&opStack) && peekChar(&opStack) != '(') {
                postfix[postfixIndex++] = popChar(&opStack);
            }
            popChar(&opStack); // Pop the open parenthesis from the stack
        } else if (isOperator(currentChar)) {
            while (!isEmptyCharStack(&opStack) && getOperatorPrecedence(peekChar(&opStack)) >= getOperatorPrecedence(currentChar)) {
                postfix[postfixIndex++] = popChar(&opStack);
            }
            pushChar(&opStack, currentChar);
        } else {
            printf("Invalid operator");
            exit(0);
        }
    }

    while (!isEmptyCharStack(&opStack)) {
        postfix[postfixIndex++] = popChar(&opStack);
    }

    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    converter(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
