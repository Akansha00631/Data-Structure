#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            // If the character is a digit, push it onto the stack
            push(c - '0');
        } else {
            // If the character is an operator, pop two elements and apply the operator
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                default: 
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
        }
    }

    // The final result will be on top of the stack
    return pop();
}

int main() {
    char postfix[MAX];

    // Input the postfix expression
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
