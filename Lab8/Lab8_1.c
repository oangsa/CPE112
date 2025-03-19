//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

    int edge, vertex, askCtr;
    scanf("%d %d", &vertex, &edge);

    int graph[vertex][vertex];

    // Graph init
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edge; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    // for (int i = 0; i < vertex; i++) {
    //     for (int j = 0; j < vertex; j++) {
    //         printf("%d ", graph[i][j]);
    //     }
    //     printf("\n");
    // }

    scanf("%d", &askCtr);

    for (int i = 0; i < askCtr; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        if (graph[v1][v2]) {
            printf("%d %d are in the graph.\n", v1, v2);
        }
        else {
            printf("%d %d are not in the graph.\n", v1, v2);
        }
    }

    return 0;
}
