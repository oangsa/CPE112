//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodes;

void initCircularList(nodes** list, int size);
void games(nodes** list, int k);

int main(void) {

    int N;
    int k;

    scanf("%d", &N);
    scanf("%d", &k);

    nodes* list = NULL;

    initCircularList(&list, N);
    games(&list, k);

    return 0;
}

void initCircularList(nodes** list, int size) {
    nodes* head = (nodes*) malloc(sizeof(nodes));
    head->data = 1;
    head->next = head;

    *list = head;

    nodes* current = head;
    for (int i = 2; i <= size; i++) {
        nodes* newNode = (nodes*) malloc(sizeof(nodes));
        newNode->data = i;
        newNode->next = head;
        current->next = newNode;
        current = newNode;
    }
}

void games(nodes** list, int k) {
    nodes* head = *list;
    nodes* current = head;
    nodes* prev = NULL;

    while (head->next != head) {
        for (int i = 0; i < k-1; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
        current = prev->next;

        head = prev;
    }

    printf("%d", head->data);
}
