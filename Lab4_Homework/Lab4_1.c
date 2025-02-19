// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int val);
void peek();
int pop();
int isEmpty();
int isFull();

int main() {

    char cmd[999];
    int val;

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "END") == 0) break;

        if (strcmp(cmd, "PUSH") == 0) {
            scanf("%d", &val);
            push(val);
        }

        if (strcmp(cmd, "POP") == 0) {
            int p = pop();
            if (p != -1) printf("%d \n", p);
        }

        if (strcmp(cmd, "PEEK") == 0) peek();
    }

    if (isEmpty()) {
        printf("Stack is empty\n");
        return 0;
    }

    while (!isEmpty()) {
        printf("%d ", pop());
    }

    return 0;
}

// Ignore this function, this function is just a handler function to make code easier to read.
int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == (MAX_SIZE - 1);
}

void push(int val) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }

    stack[++top] = val;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top--];
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("%d \n", stack[top]);
}
