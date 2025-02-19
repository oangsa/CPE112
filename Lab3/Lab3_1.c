// Suthang Sukrueangkun
// 67070503477

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int value;
  struct node* next;
} nodes;

void insertEnd(nodes* list, int data);
void insertFront(nodes** list, int data);
void printList(nodes* list);
void freeList(nodes** list);

int main(void) {

    int size;
    int mode;
    int val;

    scanf("%d", &size);
    scanf("%d", &mode);

    nodes* list = NULL;

    if (size <= 0 || (mode != 1 && mode != 2)) {
        printf("Invalid");
        return 1;
    }

    // Mode 1 = front, Mode 2 = end
    for(int i = 0; i < size; i++) {
        scanf("%d", &val);
        if (mode == 1) insertFront(&list, val);
        else insertEnd(list, val);
    }


    printList(list);

    return 0;

}



void insertEnd(nodes* list, int data) {

    if (list == NULL) {
        list = (nodes*) malloc(sizeof(nodes));
        list->value = data;
        list->next = NULL;
        return;
    }

    nodes* newNode = (nodes*) malloc(1 * sizeof(nodes));
    newNode->value = data;
    newNode->next = NULL;

    nodes* head = list;

    while(list->next != NULL) {
        list = list->next;
    }
    list->next = newNode;
    list = head;


}

void insertFront(nodes** list, int data) {
    if (*list == NULL) {
        (*list) = (nodes*) malloc(sizeof(nodes));
        (*list)->value = data;
        (*list)->next = NULL;
        return;
    }

    nodes* newNode = (nodes*) malloc(1 * sizeof(nodes));
    newNode->value = data;
    newNode->next = *list;
    *list = newNode;
}

void freeList(nodes** list) {
    for (nodes* n = *list; ; n = n->next) {
        free(n);
        if (n->next == NULL) break;
    }
}

void printList(nodes* list) {

    if (list == NULL) {
        printf("Invalid");
        return;
    }

    for (nodes* n = list; ; n = n->next) {
        printf("%d ", n->value);
        if (n->next == NULL) break;
    }
}
