//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10

typedef struct _node {
    int priority;
    int value;
    struct _node* next;
} node;

typedef struct _PriorityQueue {
    node* head;
    int size;
} PriorityQueue;

PriorityQueue pq = {
    .head = NULL,
    .size = 0
};

void enqueue(int prio, int val);
void dequeue();
void peek();

int isEmpty();
int isFull();

int main(void) {
    char cmd[99];

    while (1) {

        scanf("%s", cmd);

        if (!strcmp(cmd, "END")) break;
        else if (!strcmp(cmd, "PEEK")) peek();
        else if (!strcmp(cmd, "DEQUEUE")) {dequeue();}
        else if (!strcmp(cmd, "ENQUEUE")) {
            int p, v; scanf("%d %d", &v, &p);
            enqueue(p, v);
        }

    }

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return 1;
    }

    while(!isEmpty()) dequeue();
    return 0;
}

int isEmpty() {
    return pq.head == NULL;
}

int isFull() {
    return pq.size == MAX_SIZE;
}

void enqueue(int prio, int val) {
    if (isFull()) {
        printf("Queue is full.\n");

        return;
    }

    node* newNode = (node*) malloc(sizeof(node));
    newNode->next = NULL;
    newNode->priority = prio;
    newNode->value = val;

    if (pq.head == NULL) {
        pq.head = newNode;
    }
    else {
        node* head = pq.head;
        node* preptr = NULL;

        while (head != NULL && head->priority > prio) {
            preptr = head;
            head = head->next;
        }

        if (preptr == NULL) {
            // insert front
            newNode->next = pq.head;
            pq.head = newNode;
        }
        else if (head == NULL) {
            // insert back
            preptr->next = newNode;
        }
        else {
            // insert middle
            newNode->next = head;
            preptr->next = newNode;
        }
    }

    pq.size++;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    node* head = pq.head;
    pq.head = pq.head->next;
    pq.size--;

    printf("%d %d\n", head->value, head->priority);

    free(head);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    node* head = pq.head;

    printf("%d %d\n", head->value, head->priority);
}
