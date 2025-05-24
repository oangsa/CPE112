//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10

typedef struct _queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} queue;

queue q = {
    .front = -1,
    .rear = -1
};

void enqueue(int data);
void dequeue();
void peek();

int isEmpty();
int isFull();

int main(void) {

    char cmd[99];

    while (1) {

        scanf(" %s", cmd);

        if (!strcmp(cmd, "END")) break;
        else if (!strcmp(cmd, "Peek")) peek();
        else if (!strcmp(cmd, "Dequeue")) {dequeue(); printf("\n");}
        else if (!strcmp(cmd, "Enqueue")) {
            int v; scanf("%d", &v);
            enqueue(v);
        }

    }

    if (isEmpty()) {
        printf("Queue is empty\n");
        return 1;
    }

    while(!isEmpty()) dequeue();
    printf("\n");

    return 0;
}

int isEmpty() {
    return q.front == q.rear;
}

int isFull() {
    return q.rear == MAX_SIZE -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    q.arr[++(q.rear)] = data;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty");
        return;
    }

    printf("%d ", q.arr[++(q.front)]);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("%d \n", q.arr[q.front + 1]);
}
