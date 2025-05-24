//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue {
    int front;
    int rear;
    int data[999];
} queue;

queue q = {
    .front = 0,
    .rear = -1
};

void enqueue(int data);
int dequeue();

// Graph BFS

int main(void) {

    int edge, vertex;

    scanf(" %d %d", &vertex, &edge);

    int graph[vertex][vertex];

    // Graph init

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edge; i++) {
        int v1, v2;
        scanf(" %d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    int visited[999] = {0};

    int start;
    scanf(" %d", &start);

    // BFS
    visited[start] = 1;
    printf("%d ", start);

    enqueue(start);

    while (q.front <= q.rear) {
        int current = dequeue();

        for (int i = 0; i < vertex; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(i);
            }
        }
    }

    return 0;
}

void enqueue(int data) {
    q.data[++q.rear] = data;
}

int dequeue() {
    return q.data[q.front++];
}
