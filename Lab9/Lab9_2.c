//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

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
int* dequeue(PriorityQueue* pq);

void dijkstra(Graph* g, int start, int destination);

int main(void) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    int v, e, start, x, y, destination, w;

    scanf(" %d %d", &v, &e);
    g->vertrices = v;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->graph[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        scanf(" %d %d %d", &x, &y, &w);
        g->graph[x][y] = w;
    }

    scanf(" %d %d", &start, &destination);

    dijkstra(g, start, destination);

    return 0;
}

Node* createNode(int data, int prio) {
    Node *newNode = (Node *)malloc(sizeof(Node));
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

int* dequeue(PriorityQueue* pq) {
    int* data = (int*) malloc(sizeof(int) * 2);
    if (!pq->list) return data;

    data[0] = pq->list->data;
    data[1]= pq->list->priority;
    Node* tmp = pq->list;

    pq->list = pq->list->next;

    free(tmp);

    return data;
}


void dijkstra(Graph* g, int start, int destination) {
    if (start == destination) {
        printf("%d \n0 ", start);
        return;
    }

    int visited[999] = {0};
    int dist[999];
    int p[999];

    PriorityQueue pq = {
        .list = NULL
    };

    for (int i = 0; i < g->vertrices; i++) {
        dist[i] = INT_MAX;
        p[i] = -1;
    }


    dist[start] = 0;
    enqueue(&pq, start, 0);

    while (pq.list != NULL) {
        // [node, cost]
        int* data = dequeue(&pq);
        int node = data[0];
        int cost = data[1];
        // printf("dd\n");

        for (int i = 0; i < g->vertrices; i++) {
            if (!g->graph[node][i]) continue;

            // If the new total weight is less than the current weight
            // then update the weight and add the node to the queue
            if ((g->graph[node][i] + cost) < dist[i]) {
                dist[i] = cost + g->graph[node][i];

                enqueue(&pq, i, cost + g->graph[node][i]);

                p[i] = node;
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        printf("-1 ");
        return;
    }

    int pa[999];
    int pl = 0;
    for (int at = destination; at != -1; at = p[at]) pa[pl++] = at;

    for (int i = pl-1; i >= 0; i--) {
        printf("%d ", pa[i]);
    }

    printf("\n%d ", dist[destination]);

    // for (int i = 0; i < g->vertrices; i++) {
    //     printf("%d : %d\n", i, dist[i]);
    // }

}
