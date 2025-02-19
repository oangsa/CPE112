//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// priority high = last
typedef struct node {
    char* name;
    int priority;
    struct node* next;
    struct node* prev;
} Nodes;

Nodes* queue = NULL;
Nodes** front = &queue;
Nodes* rear = NULL;

int minPrio;

void enqueue(char* name, int prio);
void dequeue();

int main(void) {
    enqueue("Ohm", 2);
    enqueue("nigga", 1);
    enqueue("test", 1);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}

void enqueue(char* name, int prio) {
    Nodes* newNode = (Nodes*) malloc(sizeof(Nodes));
    newNode->name = (char*) malloc(strlen(name) + 1);
    strcpy(newNode->name, name);
    newNode->priority = prio;

    if ((*front) == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        queue = newNode;
        (*front) = newNode;
        rear = newNode;
    } else {
        if (prio < (*front)->priority) {
            newNode->next = (*front);
            newNode->prev = NULL;
            (*front)->prev = newNode;
            (*front) = newNode;
            queue = newNode;
        }
        else {
            Nodes* cur = (*front);

            while (cur->next != NULL && cur->next->priority <= prio) cur = cur->next;

            newNode->next = cur->next;
            newNode->prev = cur;

            if (cur->next != NULL) cur->next->prev = newNode;

            cur->next = newNode;
        }
    }
}

void dequeue() {
    if((*front) == NULL) {
        printf("Queue is underflow.\n");
        return;
    }

    Nodes* tmp = (*front);

    char* data = (*front)->name;
    (*front) = (*front)->next;

    printf("Dequeue '%s'\n", data);

    free(tmp->name);
    free(tmp);
}
