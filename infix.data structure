#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Stack structure
#define MAX 100
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    
    while ((c = infix[i++]) != '\0') {
        if (isdigit(c)) {
            postfix[j++] = c; // Add operands to postfix expression
        } else if (c == '(') {
            push(c); // Push '(' onto the stack
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '(' is found
            }
            pop(); // Remove '(' from the stack
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop(); // Pop operators with higher precedence
            }
            push(c); // Push the current operator
        }
    }
    
    while (top != -1) { // Pop remaining operators
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    int stack[MAX];
    int top = -1, i = 0;
    char c;
    
    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            stack[++top] = c - '0'; // Convert character to integer and push
        } else { // Operator
            int b = stack[top--];
            int a = stack[top--];
            switch (c) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    
    return stack[top]; // Result of the evaluation
}

int main() {
    char infix[MAX], postfix[MAX];

    // Input the infix expression
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
