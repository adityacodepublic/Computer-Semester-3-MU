#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack data structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // $ denotes an empty stack
}

// Function to return the top element of the stack without popping
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert an infix expression to a prefix expression
void infixToPrefix(char* infix, char* prefix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j = 0;

    // Reverse the input infix expression
    for (i = strlen(infix) - 1; i >= 0; i--) {
        if (infix[i] == ' ')
            continue;

        if (isdigit(infix[i]) || isalpha(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(stack, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(stack) && peek(stack) != ')') {
                prefix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != ')') {
                printf("Invalid expression.\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && getPrecedence(infix[i]) < getPrecedence(peek(stack))) {
                prefix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression to get the correct order
    int len = strlen(prefix);
    for (i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* prefix) {
    struct Stack* stack = createStack(strlen(prefix));
    int i, operand1, operand2, result;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            operand1 = pop(stack);
            operand2 = pop(stack);
            switch (prefix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(stack, result);
        }
    }

    return pop(stack);
}

int main() {
    char infix[100], prefix[100];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}
