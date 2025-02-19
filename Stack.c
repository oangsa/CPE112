//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

#define MAX_STACK 999

void pop(int stack[MAX_STACK], int *top);
void push(int stack[MAX_STACK], int *top, int val);

int main(void) {
    int top = -1;
    int stack[MAX_STACK];

    pop(stack, &top);

    push(stack, &top, 5);
    push(stack, &top, 10);

    pop(stack, &top);

    return 0;
}

void push(int stack[MAX_STACK], int *top, int val) {
    if (*top == MAX_STACK - 1) {
        printf("Stack is full.\n");
        return;
    }

    stack[(*top)++] = val;
}

void pop(int stack[MAX_STACK], int *top) {
    if (*top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Pop %d from the stack.\n" ,stack[--(*top)]);
}
