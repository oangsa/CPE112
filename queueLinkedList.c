//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* tail = NULL;
Node** rear = &tail;
Node* front = NULL;

void enqueue(int data);
int dequeue();

int main(void) {

    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("Front of queue: %d\n", front->data);
    printf("Tail of queue: %d\n", tail->data);

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    printf("Front of queue: %d\n", front->data);

    enqueue(99);

    printf("Tail of queue: %d\n", tail->data);

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());


    return 0;
}

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (front == NULL) {

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        front = newNode;
        tail = newNode;
    }
    else {
        newNode->data = data;
        (*rear)->next = newNode;
        newNode->prev = *rear;
        newNode->next = NULL;

        tail = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    Node* tmp = front;
    int data = front->data;

    front = front->next;

    free(tmp);

    return data;
}
