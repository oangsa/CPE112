// This Graph Implemented Using LinkedList. So, it might be a little differences in term of the add edge algorithm. GL guys

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int vertex;
    struct _node *next;
} node;

typedef struct _graph {
    int verticeCount;
    node **adj_list;
} graph;

graph* createGraph(int verticeCount) {
    graph* g = (graph*) malloc(sizeof(graph));

    g->verticeCount = verticeCount;
    g->adj_list = (node**) malloc(sizeof(node*) * verticeCount);

    for (int i = 0; i < verticeCount; i++) {
        g->adj_list[i] = NULL;
    }

    return g;
}

node* createNode(int vertex) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(graph* g, int vertex1, int vertex2) {
    node* newNode = createNode(vertex2);

    node* tmp = g->adj_list[vertex1];

    if (!tmp) {
        g->adj_list[vertex1] = newNode;
    }
    else {
        node* cur = tmp;
        node* preptr = NULL;

        while (cur != NULL && cur->vertex < vertex2) {
            preptr = cur;
            cur = cur->next;
        }

        if (!preptr) {
            newNode->next = cur;
            g->adj_list[vertex1] = newNode;
        }
        else {
            newNode->next = cur;
            preptr->next = newNode;
        }
    }

    node* newNode2 = createNode(vertex1);

    node* tmp2 = g->adj_list[vertex2];

    if (!tmp2) {
        g->adj_list[vertex2] = newNode2;
    }
    else {
        node* cur = tmp2;
        node* preptr = NULL;

        while (cur != NULL && cur->vertex < vertex1) {
            preptr = cur;
            cur = cur->next;
        }

        if (!preptr) {
            newNode2->next = cur;
            g->adj_list[vertex2] = newNode2;
        }
        else {
            newNode2->next = cur;
            preptr->next = newNode2;
        }
    }
}

void dfsUtils(graph* g, int idx, int visited[]) {
    visited[idx] = 1;
    node* vertex = g->adj_list[idx];

    printf("%d ", idx);

    while (vertex) {
        if (!visited[vertex->vertex]) {
            dfsUtils(g, vertex->vertex, visited);
        }
        vertex = vertex->next;
    }
}

void dfs(graph* g, int vertex) {
    int visited[999] = {0};
    dfsUtils(g, vertex, visited);
}

void bfs(graph* g, int vertex) {
    int visited[999] = {0};
    int queue[999];
    int front = 0, rear = -1;

    queue[++rear] = vertex;
    visited[vertex] = 1;

    while (front <= rear) {
        int idx = queue[front++];
        printf("%d ", idx);

        node* temp = g->adj_list[idx];
        while (temp != NULL) {
            int adjIdx = temp->vertex;
            if (!visited[adjIdx]) {
                visited[adjIdx] = 1;
                queue[++rear] = adjIdx;
            }
            temp = temp->next;
        }
    }
}

int main() {
    graph* g = createGraph(6);

    addEdge(g, 3, 1);
    addEdge(g, 2, 3);
    addEdge(g, 1, 2);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 4);
    addEdge(g, 4, 3);

    printf("DFS Traversal: ");
    dfs(g, 3);
    printf("\n");

    printf("BFS Traversal: ");
    bfs(g, 3);
    printf("\n");

    return 0;
}
