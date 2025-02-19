//Suthang Sukrueangkun
//67070503477

#include<stdio.h>

#define MAX_SIZE 2

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int val);
int dequeue();
int isFull();
int isEmpty();

int main(void) {
    dequeue();
    enqueue(1);
    enqueue(3);
    dequeue();
    enqueue(3);
    return 0;
}

int isEmpty() {
    return rear == front;
}

int isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is overflow.\n");
        return;
    }

    queue[++rear] = val;
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty or underflow.\n");
        return -1;
    }

    printf("%d has been dequeue\n", queue[++front]);
}
