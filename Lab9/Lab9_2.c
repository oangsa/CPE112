//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node {
    int data;
    int priority;
    struct _Node* next;
} Node;

typedef struct _PriorityQueue {
    Node* list;
} PriorityQueue;

typedef struct _Graph {
    int vertrices;
    int graph[999][999];
} Graph;

Node* createNode(int data, int prio);

void enqueue(PriorityQueue* pq, int data, int prio);
int dequeue(PriorityQueue* pq);

void dijkstra(Graph g, int start, int destination);

int main(void) {
    PriorityQueue pq = {
        .list = NULL
    };

    Graph g;

    int v, e, start, x, y, destination;

    scanf(" %d", &v, &e);
    g.vertrices = v;

    for (int i = 0; i < e; i++) {
        scanf(" %d %d", &x, &y);
        g.graph[x][y] = 1;
        g.graph[y][x] = 1;
    }

    scanf(" %d %d", &start, &destination);

    return 0;
}

Node* createNode(int data, int prio) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = prio;
    newNode->next = NULL;

    return newNode;
}

void enqueue(PriorityQueue* pq, int data, int prio) {
    Node* head = pq->list;
    Node* newNode = createNode(data, prio);

    if (!head) {
        pq->list = newNode;
    }
    else {
        Node* cur = pq->list;
        Node* preptr = NULL;

        while (cur != NULL && cur->priority < prio) {
            preptr = cur;
            cur = cur->next;
        }

        if (!preptr) {
            newNode->next = cur;
            pq->list = newNode;
        }
        else {
            newNode->next = cur;
            preptr->next = newNode;
        }

    }

}

int dequeue(PriorityQueue* pq) {
    if (!pq->list) return -1;

    int data = pq->list->data;
    Node* tmp = pq->list;

    pq->list = pq->list->next;

    free(tmp);

    return data;
}


void dijkstra(Graph g, int start, int destination) {
    int visited[g.vertrices] = {0};

}
