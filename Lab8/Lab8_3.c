//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dfs(int vertex, int graph[999][999], int start);
void dfsUtils(int vertex, int graph[999][999], int visited[999], int start);

int main(void) {

    int edge, vertex;

    scanf("%d %d", &vertex, &edge);

    int graph[999][999];

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

    int start;
    scanf(" %d", &start);

    // DFS
    dfs(vertex, graph, start);

    return 0;
}

void dfs(int vertex, int graph[999][999], int start) {
    int visited[999] = {0};
    dfsUtils(vertex, graph, visited, start);
}

void dfsUtils(int vertex, int graph[999][999], int visited[999], int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < vertex; i++) {
        if (graph[start][i] && !visited[i]) {
            dfsUtils(vertex, graph, visited, i);
        }
    }
}
