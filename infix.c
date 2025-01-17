#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    
    while ((c = infix[i++]) != '\0') {
        if (isdigit(c)) {
            postfix[j++] = c; 
        } else if (c == '(') {
            push(c); 
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(); 
            }
            pop(); 
        } else { 
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop(); 
            }
            push(c);
        }
    }
    
    while (top != -1) { 
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; 
}

int evaluatePostfix(char* postfix) {
    int stack[MAX];
    int top = -1, i = 0;
    char c;
    
    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            stack[++top] = c - '0'; 
        } else { 
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
    
    return stack[top]; 
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
i   nt  result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
