//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Edge {
    int vertex1;
    int vertex2;
    int weight;
} Edge;
typedef struct _Graph {
    int vertrices;
    Edge* edges;
    int edgeCount;
} Graph;

Graph* init(int vertrices);
void addEdge(Graph** g, int vertex1, int vertex2, int weight);
void sortEdges(Graph* g);
void kruskal(Graph* g);
int find(int* parent, int i);
void unionSet(int* parent, int x, int y);

int main(void) {

    int v, e, x, y, w;

    scanf(" %d %d", &v, &e);

    Graph* g = init(v);

    for (int i = 0; i < e; i++) {
        scanf(" %d %d %d", &x, &y, &w);
        addEdge(&g, x, y, w);
    }

    kruskal(g);

    return 0;
}

Graph* init(int vertrices) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->vertrices = vertrices;
    g->edges = (Edge*) malloc(sizeof(Edge) * vertrices * vertrices);
    g->edgeCount = 0;
    return g;
}

void addEdge(Graph** g, int vertex1, int vertex2, int weight) {
    (*g)->edges[(*g)->edgeCount].vertex1 = vertex1;
    (*g)->edges[(*g)->edgeCount].vertex2 = vertex2;
    (*g)->edges[(*g)->edgeCount].weight = weight;
    (*g)->edgeCount++;
}

void sortEdges(Graph* g) {
    for (int i = 0; i < g->edgeCount - 1; i++) {
        for (int j = 0; j < g->edgeCount - i - 1; j++) {
            if (g->edges[j].weight > g->edges[j + 1].weight) {
                Edge temp = g->edges[j];
                g->edges[j] = g->edges[j + 1];
                g->edges[j + 1] = temp;
            }
        }
    }
}

int find(int* parent, int i) {
    if (parent[i] == -1) {
        return i;
    }
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSet(int* parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);

    if (xset != yset) {
        parent[xset] = yset;
    }
}

void kruskal(Graph* g) {
    Edge* result = (Edge*) malloc(sizeof(Edge) * g->vertrices);
    int totalWeight = 0;
    int e = 0;
    int i = 0;
    int* parent = (int*) malloc(sizeof(int) * g->vertrices);

    for (int i = 0; i < g->vertrices; i++) {
        parent[i] = -1;
    }

    sortEdges(g);

    while (e < g->vertrices - 1 && i < g->edgeCount) {
        Edge nextEdge = g->edges[i++];

        int x = find(parent, nextEdge.vertex1);
        int y = find(parent, nextEdge.vertex2);

        if (x != y) {
            result[e++] = nextEdge;
            unionSet(parent, x, y);
        }
    }

    for (int i = 0; i < e; i++) {
        totalWeight += result[i].weight;
        printf("%d %d %d\n", result[i].vertex1, result[i].vertex2, result[i].weight);
    }

    printf("Total Weight: %d\n", totalWeight);
}
