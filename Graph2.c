//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
    int vertex;
    struct _node* next;
} node;

typedef struct _graph {
    int vertrices;
    node** matrix;
} graph;

graph* createGraph(int vertrices);
graph* addEdge(graph* g, int vertex1, int vertex2);
node* createNode(int vertex);

void dfs(graph* g, int start);
void dfsUtils(graph* g, int start, int visited[]);

int main(void) {

    graph* g = createGraph(6);

    g = addEdge(g, 3, 1);
    g = addEdge(g, 2, 3);
    g = addEdge(g, 1, 2);
    g = addEdge(g, 0, 1);
    g = addEdge(g, 0, 4);
    g = addEdge(g, 1, 4);
    g = addEdge(g, 4, 3);

    dfs(g, 3);

    return 0;
}

graph* createGraph(int vertrices) {
    graph* g = (graph*) malloc(sizeof(graph));

    g->vertrices = vertrices;
    g->matrix = (node**) malloc(sizeof(node*) * vertrices);

    for(int i = 0; i < vertrices; i++) {
        g->matrix[i] = NULL;
    }

    return g;
}

graph* addEdge(graph* g, int vertex1, int vertex2) {
    node* newNode = createNode(vertex2);

    node* tmp = g->matrix[vertex1];

    //Insert LinkedList

    if (!tmp) {
        g->matrix[vertex1] = newNode;
    }
    else {
        node* cur = tmp;
        node* preptr = NULL;

        while (cur != NULL && cur->vertex < vertex2) {
            preptr = cur;
            cur = cur->next;
        }

        if (!preptr) {
            newNode->next = g->matrix[vertex1];
            g->matrix[vertex1] = newNode;
        }
        else {
            newNode->next = cur;
            preptr->next = newNode;
        }
    }

    node* newNode2 = createNode(vertex1);
    tmp = g->matrix[vertex2];

    if (!tmp) {
        g->matrix[vertex2] = newNode2;
    }
    else {
        node* cur = tmp;
        node* preptr = NULL;

        while (cur != NULL && cur->vertex < vertex1) {
            preptr = cur;
            cur = cur->next;
        }

        if (!preptr) {
            newNode2->next = g->matrix[vertex2];
            g->matrix[vertex2] = newNode2;
        }
        else {
            newNode2->next = cur;
            preptr->next = newNode2;
        }
    }

    return g;
}

node* createNode(int vertex) {
    node* newNode = (node*) malloc(sizeof(node));

    newNode->next = NULL;
    newNode->vertex = vertex;

    return newNode;
}

void dfs(graph* g, int start) {
    int visited[999] = {0};

    dfsUtils(g, start, visited);
}

void dfsUtils(graph* g, int start, int visited[]) {
    visited[start] = 1;
    node* tmp = g->matrix[start];

    printf("%d ", start);

    while (tmp != NULL) {
        if(!visited[tmp->vertex]) {
            dfsUtils(g, tmp->vertex, visited);
        }
        tmp = tmp->next;
    }
}
