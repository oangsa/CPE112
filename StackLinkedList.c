//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;


Node *tail = NULL;
Node **top = &tail;
Node *head = NULL;

void push(int data);
int pop();
int peek();


int main(void) {
    push(1);
    push(2);

    printf("Top of stack: %d\n", peek());

    printf("Head of stack: %d\n", head->data);

    printf("Pop: %d\n", pop());

    printf("Top of stack: %d\n", peek());

    push(3);

    printf("Head of stack: %d\n", head->data);

    printf("Top of stack: %d\n", peek());

    return 0;
}

void push(int data) {
    Node *newNode = (Node*) malloc (sizeof(Node));

    Node *tmp = tail;

    if (tail == NULL) {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;

        tail = newNode;

    }
    else {
        newNode->data = data;
        (*top)->next = newNode;
        newNode->prev = *top;

        *top = newNode;
    }
}

int pop() {
    Node *tmp = *top;

    if (tmp == NULL) {
        return -1;
    }

    int data = tmp->data;

    if (tmp->prev == NULL) {
        head = NULL;
    }
    else {
        *top = tmp->prev;
        (*top)->next = NULL;
    }

    free(tmp);
    return data;
}

int peek() {
    return (*top)->data;
}
