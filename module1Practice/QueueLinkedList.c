//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodes;

nodes* head = NULL;
nodes* tail = NULL;

void push(int value);
int pop();
int peek();

int main(void) {

    pop();
    printf("%d\n", peek());
    push(1);
    push(2);
    push(3);
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());

    return 0;
}

void push(int value) {
    nodes* nn = (nodes*) malloc(sizeof(nodes));
    nn->next = NULL;
    nn->data = value;

    if (head == NULL) {
        head = nn;
        tail = nn;
    }
    else {
        tail->next = nn;
        tail = nn;
    }

}

int pop() {

    if (head == NULL) {
        printf("Queue is underflow\n");
        return -999999;
    }

    nodes* tmp = head;
    head = head->next;

    int d = tmp->data;
    free(tmp);

    return d;

}

int peek() {
    if (head == NULL) {
        printf("Queue is underflow\n");
        return -999999;
    }

    return head->data;
}
