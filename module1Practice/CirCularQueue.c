// Suthang Sukrueangkun
// 67070503477

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int val);
void dequeue();

int main(void) {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(1);
    dequeue();

    return 0;
}

void enqueue(int val) {
    if (rear == MAX_SIZE - 1 && front == -1) {
        printf("Queue is overflow.\n");
        return;
    }

    rear = (++rear) % MAX_SIZE;

    queue[rear] = val;
}

void dequeue() {
    if (rear == front) {
        printf("Queue is overflow.\n");
        return;
    }

    front = (++front) % MAX_SIZE

    printf("%d has been dequeue.\n", queue[front]);
}
