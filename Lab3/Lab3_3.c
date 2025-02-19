// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node* prev;
  struct node* next;
} nodes;

void add(nodes** list, int value);
void printList(nodes* list);
void search(nodes* list, int value);
void delete(nodes** list, int value);


int main(void) {

    char cmd[999];
    int val;

    // construct the doubly linked list

    nodes *list = NULL;


    // ADD => add the newNode at the back, DEL => delete the first node that has the value equal to the given value, SCH => print the value of the prev and next of the given node
    // END => print all the values in the list and end the program

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "END") == 0) break;

        scanf("%d", &val);

        if (strcmp(cmd, "ADD") == 0) {
            add(&list, val);
        }

        if (strcmp(cmd, "DEL") == 0) {
            delete(&list, val);
        }

        if (strcmp(cmd, "SCH") == 0) {
            search(list, val);
        }
    }

    printList(list);

    return 0;
}

void search(nodes* list, int value) {
    nodes* cur = list;

    while (cur != NULL) {
        if (cur->data == value) {
            if (cur->prev == NULL) {
                printf("NULL ");
            }
            else {
                printf("%d ", cur->prev->data);
            }

            if (cur->next == NULL) {
                printf("NULL\n");
            }
            else {
                printf("%d\n", cur->next->data);
            }
            return;
        }

        cur = cur->next;
    }

    printf("none\n");
}

void delete(nodes** list, int value) {
    nodes* cur = *list;

    // Delete the first node that has the value equal to the given value
    while (cur != NULL) {
        if (cur->data == value) {
            nodes* prev = cur->prev;
            nodes* next = cur->next;
            if (prev == NULL) {
                *list = next;
            }
            else {
                prev->next = next;
            }

            if (next != NULL) {
                next->prev = prev;
            }

            free(cur);
            return;
        }

        cur = cur->next;
    }
}

void add(nodes** list, int data) {

    nodes* newNode = (nodes*) malloc(sizeof(nodes));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
    }
    else {
        nodes* cur = *list;
        while (cur->next != NULL) {
            cur = cur->next;
        }

        cur->next = newNode;
        newNode->prev = cur;
    }
}

void printList(nodes* list) {
    nodes* cur = list;
    nodes* back = NULL;

    if (cur == NULL) {
        printf("none\n");
        printf("none");
        return;
    }

    while (cur != NULL) {
        printf("%d ", cur->data);

        back = cur;
        cur = cur->next;
    }

    printf("\n");

    while (1) {
        printf("%d ", back->data);

        if (back->prev == NULL) break;

        back = back->prev;
    }
}
