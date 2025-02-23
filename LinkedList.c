//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Nodes;

void freeNodes(Nodes** n);
void searchValue(Nodes* n, int value);
void insertValue(Nodestouch ** nodes, int value);
void pushValue(Nodes* nodes, int value);
void pop(Nodes* nodes);

int main(void) {

    Nodes *n;

    n = (Nodes*) malloc (1 * sizeof(Nodes));

    n->value = 1;
    n->next = NULL;

    for(int i = 2; i < 10; i++) {
        Nodes *newNode;
        newNode = (Nodes*) malloc (1 * sizeof(Nodes));

        // Insert
        newNode->value = i;
        newNode->next = n;

        n = newNode;
    }

    insertValue(&n, 11);
    pushValue(n, 12);

    searchValue(n, 12);
    searchValue(n, 13);

    // Print the value
    for (Nodes* nodes = n; ; nodes = nodes->next) {
        printf("%d\n", nodes->value);
        if (nodes->next == NULL) break;
    }

    freeNodes(&n);

    // // Free all the nodes
    // for (Nodes* nodes = n; ; nodes = nodes->next) {
    //     free(nodes);
    //     if (nodes->next == NULL) break;
    // }

    return 0;
}

void insertValue(Nodes** nodes, int value) {
    Nodes* newNode = (Nodes*) malloc (1 * sizeof(Nodes));
    newNode->value = value;
    newNode->next = *nodes;

    *nodes = newNode;
}

void pushValue(Nodes* nodes, int value) {
    Nodes* newNode = (Nodes*) malloc (1 * sizeof(Nodes));
    newNode->value = value;
    newNode->next = NULL;

    while(nodes->next != NULL) {
        nodes = nodes->next;
    }

    nodes->next = newNode;
}

void searchValue(Nodes* n, int value) {
    for (Nodes* nodes = n; ; nodes = nodes->next) {
        if (nodes->value == value) {
            printf("Value '%d' is in the list.\n", value);
            return;
        }
        if (nodes->next == NULL) break;
    }
    printf("Value '%d' is not in the list.\n", value);
}

void freeNodes(Nodes** n) {
    for (Nodes* nodes = *n; ; nodes = nodes->next) {
        free(nodes);
        if (nodes->next == NULL) break;
    }
}
