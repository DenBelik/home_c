#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

void clear(Node** top) {
    while (*top != NULL) {
        Node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int operate(int a, int b, char op) {
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    
    default:
        break;
    }
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int calculate() {
    Node* stack = NULL;
    char c;
    int num = 0;
    int result = 0;

    while ((c = getchar()) != '.') {
        if (isdigit(c)) {
            while(isdigit(c)) {
                num = num * 10 + (c - '0');
                c = getchar();
            }
            push(&stack, num);
            num = 0;
        }
        if (is_operator(c)) {
            int b = pop(&stack);
            int a = pop(&stack);
            result = operate(a, b, c);
            push(&stack, result);
        }
    }
    clear(&stack);
    return result;
}

int main(void) {

    printf("%d", calculate());

    return 0;
}